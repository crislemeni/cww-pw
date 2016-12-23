<!DOCTYPE html>
<html>
<head>
<!-- everything here is 100% free to use as you wish -->
<meta charset="utf-8">
<title>Camp Walt Whitman – Photo Galleries</title>


<!-- styles for this demo -->
<style>
html, body {
	/*background:#111 url(broken_noise.png);*/
	font:13px/1.3 arial, sans-serif;
	height: 100%;
	overflow:hidden;
	margin:0;
	padding:0;
}
a {
	color:#823;
	text-decoration:none
}
#container {
	width:100%;
}
#gallery {
	width:100%;
	height:100%;
}
#galleria {
	width:100%;
	height:100%;
	background:#000
}
#loader {
	width:200px;
	height:100px;
	margin:-50px 0 0 -100px;
	position:absolute;
	left:50%;
	top:50%;
	color:#fff;
	text-align:center;
	z-index:4;
	display:none;
	/*background:#000 url('/site/templates/images/fsgallery/loader.gif') no-repeat 50% 25px;*/
	opacity:.8;
	line-height:150px;
	border-radius:6px
}
#menu {
	position:absolute;
	top: 20px;
	right: 10px;
	z-index: 11000;
	background:rgb(76, 110, 34);
	background:rgba(76, 110, 34, 0.61);
	padding: 5px 5px 4px;
	border-radius: 5px;
	border: 1px solid #fff;
}
#menu ul {
	list-style: none outside;
	margin:0;
	padding:0;
}
#menu ul a {
	display:block;
	padding: 6px;
	color: white;
}
#menu ul a:hover {
	background:#151515;
	background:#43601e;
	background:rgba(0, 0, 0, .1);
}
#menu a.active {
	background:#111;
	background:#43601e;
	background:rgba(0, 0, 0, .3);
	color:#fff
}
#menu p {
	color:white;
	width: 122px;
	margin:0;
	padding:3px 0px 0;
	cursor: pointer;
	text-align: center;
}
.logo {
	position:absolute;
	z-index:11200;
	top:10px;
	left:20px;
}
a.backToWebsite {
	position: absolute;
	top: 118px;
	left: 121px;
	font-weight: bold;
	color: white;
	text-shadow: 1px 1px 1px black;
}
#playToggle {
	position:absolute;
	left:-70px;
	background:url('/site/templates/images/fsgallery/playPause.gif') no-repeat left top;
	text-align:center;
	width:57px;
	height: 57px;
	padding: 0 !important;
	text-indent: -999em;
	border-radius: 5px;
	top: 0;
}
#playToggle.play {
	background:url('/site/templates/images/fsgallery/playPause.gif') no-repeat left bottom;
}
</style>
<!-- load jQuery -->
<script src="http://ajax.googleapis.com/ajax/libs/jquery/1/jquery.min.js"></script>

<!-- load Galleria -->
<script src="/site/templates/js/galleria-1.2.8.min.js"></script>

<!-- load flickr plugin -->
<script src="/site/templates/js/plugins/flickr/galleria.flickr.min.js"></script>
</head>
<body>

<div class="logo"> <img src="/site/templates/images/logo.png" alt="Camp Walt Whitman Logo" /> <a href="/" class="backToWebsite">&laquo; back to website</a> </div>
<!-- end logo-->
<div id="menu"> <a href="#" id="playToggle" class="pause">Pause Slide-Show</a>
	<p><img src="/site/templates/images/fsgallery/selectGallery.gif" alt="Select Photo Gallery" /></p>
	<ul>
		<?php foreach ($page->fs_albums as $album): ?>
		<li><a href="<?= $album->flickr_url?>"><?= $album->title?></a></li>
		<?php endforeach ?>
		
	</ul>
	
</div>
<!-- end #menu-->
<div id="container">
	<div id="gallery">
		<div id="galleria"></div>
	</div>
</div>
<!-- end #container--> 
<script>

        // load the theme
        Galleria.loadTheme('/site/templates/js/js/themes/fullscreen/galleria.fullscreen.min.js');

        // create a flickr instance
        var flickr = new Galleria.Flickr();

        // cache the gallery
        var elem = $('#galleria');
        // create and append the loader growl
        var loader = $('<div>', {
            id: 'loader'
        }).appendTo('#gallery');

        // a local var used later
        var set;

        // set flickr to fetch description and increase the photo limit
        flickr.setOptions({
            max: 100,
            description: true
        });

        // attach event handler for the menu
        $('#menu ul a').click(function(e) {
				
        	Galleria.configure({
    			_hideDock: false,
    			transition: 'fade',
    			autoplay: 6000,
    			transitionSpeed: 1000,
    			pauseOnInteraction: true,
    			showInfo: false,
    			responsive: true,
    			initialTransition: 5000,
    			imageCrop: 'landscape'
			});
		
            e.preventDefault();

            // toggle active class
            $('#menu a').removeClass('active');
            $(this).addClass('active')
            $('#menu ul').slideUp();

            // extract the set id from the link href
            set = this.href.split('/');
            set = set[set.length-2];

            // add loader text and show
            loader.text('Loading '+$(this).text()).show();

            // load the set
            flickr.set(set, function(data) {

                // hide the loader
                loader.fadeOut('fast');

                // check if galleria has been initialized
                if (elem.data('galleria')) {

                    // load galleria with the new data
                    elem.data('galleria').load( data );

                // else initialize galleria (1st time)
                } else {
                    elem.galleria({

                        // add the data as dataSource
                        dataSource: data                
                    });
                }
            });
             
        });


		$('#menu p').click(function(){
			$('#menu ul').slideToggle();
		});
        // trigger a click onload so that the first gallery will be displayed when entering

            <?php if (isset($_GET['id']) && $_GET['id'] == 'alumni') : ?>
				$("#menu ul li a").each(function(){

			        if($(this).text().match("Alumni")){
			            $(this).click();
			        }
			    });
			<?php else: ?>

				$('#menu li:first a').click();
				
			<?php endif?>


        
        $('#menu ul').slideUp();
        
         var playing = true;
         
        $('#playToggle').click(function() {
			$(this).toggleClass("play");
        	if (playing == true) {
        		$(this).text("Play Slide-Show");
        		$('#galleria').data('galleria').pause();
        		playing = false;	
        	}else{
        		$(this).text("Pause Slide-Show");
        		$('#galleria').data('galleria').play();
        		playing = true;
        	};	
        	return false;
		});
		

		$(window).resize(function() {
    		 window.location.href = window.location.href;
		});
 
    </script>

</body>
</html>