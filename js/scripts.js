//$('.imagesHolder').cycle({
  //  	fx:'scrollHorz',
    //    next: '.arrowRight',
      //  prev: '.arrowLeft'
//	});
$(window).load(function(){
      $('.slideshowHolder').flexslider({
        animation: "slide",
		slideshow: true,
		controlNav: false
      });
	  // new this summer
//	  $('.whatsNew').flexslider({
//        animation: "slide",
//		slideshow: true,
//		controlNav: true
  //    });
	  
	  
});




// menu dropdown for responsive
$("#showSubmenu").click(function(){
              $(".sidebarHolder").slideToggle("slow"); 
			     $(this).toggleClass("activeDropdown"); 
    });

// $('.neverDoneBefore .imagesHolderNDB').cycle({
   // 	fx:'fade',
	//	timeout: 10000,
    //    next: '.arrowRight',
    //    prev: '.arrowLeft'
//	});
	
// Function for animating the FAQs
	$questions = $('h3.faq_question a');
	$answers = $('div.faq_answer');
	$answers.hide();

	$questions.click(function() {

		if ($(this).parent().next().is(":hidden")) {
	    	$answers.hide();
	    	$(this).parent().next().slideDown();
		}else{
			$(this).parent().next().slideUp();
		}
		return false;
});

// JQuery Inline Validation Instantiation goes here:
$("#contactForm").validationEngine('attach');
$("#alumniForm").validationEngine('attach');
// function for checking the captcha
function checkCaptcha(field, rules, i, options){
	var op1 = parseInt($('#operator1').html());
	var op2 = parseInt($('#operator2').html());
	var sign = $('#operand').html();

	if (sign=="+") {
		var result = op1 + op2;
	}else{
		var result = op1 - op2;
	};

	if (field.val() != result) {
		//this allows the use of i18 for the error msgs
		return '* the correct answer is <b style="font-size:16px;"> ' + result +' </b>,<br /> &nbsp; &nbsp; please enter it here';
	}
}


// calendar 

$(document).ready(function() {

	// previous and next nav
	$(document).on('click', '#Calendar a.prev, #Calendar a.next', function() {
		var cal = $(this).parentsUntil('.calendar').parent();
		var href = $(this).attr('href');
		
		$(cal).css('opacity', 0.7);

		var width = $(cal).css('width');
		var height = $(cal).css('height');
		
		$(cal).parent().find('.cover').css({'width': width, 'height': height, 'margin-top': '-' + height}).show();
		
		$.get(href, function(data) {
				$(cal).parent().find('.cover').hide();
				$('#Calendar .calendar').replaceWith(data);
			}
		)
		return false;    
	})

	// $('th.dow').each(function(imdex){

	// 	switch ($(this).text()) {
	// 		case "Mo":
	// 		  $(this).text("Mon")
	// 		  break;
	// 		case "Tu":
	// 		  $(this).text("Tue")
	// 		  break;
	// 		case "We":
	// 		   $(this).text("Wed")
	// 		   break;
	// 		case "Th":
	// 		  $(this).text("Thu")
	// 		  break;
	// 		case "Fr":
	// 		  $(this).text("Fri")
	// 		  break;
	// 		case "Sa":
	// 		  $(this).text("Sat")
	// 		  break;
	// 		case "Su":
	// 		  $(this).text("Sun")
	// 		  break; 
	// 	}
	// });

	// event mouse over
	//$('#Calendar .isevent').live('mouseenter',function() {
	//	id = this.id;
//		$('#' + id + ' .event').show();
//	})
//	$('#Calendar .isevent').live('mouseleave',function() {
//		id = this.id;
//		$('#' + id + ' .event').hide();
//	})        

	//galery image download link 
	$('.gal-item-active').hover(
		function () {
    		$(this).append($('<span style="display: block;position:absolute; bottom: 5px;left: 0px; text-align:center; padding:3px;background-color:rgba(255,255,255,0.8); width:170px"><a href="'+$(this).find("a").attr("data-fullImg")+'" target="_blank">download big image</a></span>'));
  		}, 
  		function () {
    		$(this).find("span:last").remove();
  		}
	);
	
});

// What's New For Me This Summer
// $('#newAgeGroup1,#newAgeGroup2,#newAgeGroup3,#newAgeGroup4').css('display', 'none');
$("document").ready(function() {
    setTimeout(function() {
        $(".newInGeneral a").trigger('click');
    },100);
});
$('div.whatsNewHeader ul li a').click(function(){
     $('div.whatsNewHeader ul li a').removeClass('active');
     $(this).addClass('active');
    
 	// $('div#' + $(this).parent().attr("class") + ' div.whatsNew').flexslider(0);
 	$('div.whatsNewSlideWrapper').hide();
 	$('div#'+$(this).parent().attr("class")).fadeIn(1000);
 	return false;
});
$('.whatsNew').flexslider({
        animation: "slide",
		slideshow: true,
		controlNav: false
});
// $('.whatsNewSlidesow').cycle({
//		fx: 'scrollHorz',
//		pager:  $(this).find('.whatsNewPager'),
//		timeout: 3000
//		//prev: $("a.arrowLeft"),
//		//next: $("a.arrowRight")
		//easing: 'easeInOutCirc'
//	});	


// *****************************
// typical day slideshow
//******************************

$('.tdSlideShow img').jail({loadHiddenImages : true});
// here we set the data placeholders to their defaults
$('body').data('selGender', 'notSet');
$('body').data('selAge', 'notSet');


// this function handles updating the main display area based on what buttons the users push
// it either displays the proper error message or one of the slideshows
// it takes it's parameters from the 2 data properties selGender and selAge
function updateSlideshow(selectedGender,selectedAge) {
	//alert('gender is: ' + selectedGender + ' and  age is: ' + selectedAge);
	if (selectedGender == 'notSet') {
		$('div.genderError').show().siblings().hide();
	}else if (selectedAge == 'notSet') {
		$('div.ageError').show().siblings().hide();
	}else{
		//alert('gender is: ' + selectedGender + ' and  age is: ' + selectedAge);

		// next we show the correct slideshow and reset it then hide all others
		$('div#slideShow-' + selectedGender + '-' + selectedAge).siblings().hide();
		$('div#slideShow-' + selectedGender + '-' + selectedAge).show().flexslider(0);

		// load the first slide's description in the HTML
		var slideDescription = $('.tdSlideShow:visible img:visible').attr('data-description');
		if (slideDescription== "") {
			slideDescription = "Missing description! Please add one in the manager.";
		}
		 $('.slideDescription').html( '<p>' + slideDescription + '</p>');

		$('#tdSlideShowNav').removeClass();// this makes the "Inactive" styling go away
		$('div.tdSlideshowNavCover').css("display", "none"); // and moves the blinder div up so we can now click on the nav buttons
		// we show the slide description and vertically align the text within
		$('div.slideDescription').show().children('p').vAlign();
		// also make the previous and next buttons visible now
		$('a#prev2, a#next2').show();

		// we trigger the preloading of the images inside of the slideshow
		$('#slideShow-' + selectedGender + '-' + selectedAge + ' img').click();
		// and we make the first nav button active.
		$('#tdSlideShowNav li:first').addClass('activeSlide').siblings().removeClass();
	};

}
// below are the two click handlers, one for age one fore gender
$('ul.genderSelector li a').click(function(){
	$('ul.genderSelector li a').removeClass();
	$(this).addClass('tdButtonSelected');
	$('body').data('selGender', $(this).attr('id'));
	updateSlideshow($('body').data('selGender'),$('body').data('selAge'));
	return false;
});
$('ul.ageSelector li a').click(function(){
	$('ul.ageSelector li a').removeClass();
	$(this).addClass('tdButtonSelected').siblings().removeClass();
	$('body').data('selAge', $(this).attr('id'));
	updateSlideshow($('body').data('selGender'),$('body').data('selAge'));
	return false;
});

// this part initializes all the 6 slideshows
$('.tdSlideShow').flexslider({
	directionNav: false, 
	slideshow: false,
	before: function() {// this part assures user won't click any more buttons while animation is playing
		$('div.tdSlideshowNavCover').css("display", "block");
	},
	after: function(slider) {
		$('div.tdSlideshowNavCover').css("display", "none");
		var slideDescription = $('.tdSlideShow:visible img:visible').attr('data-description');
		if (slideDescription== "") {
			slideDescription = "Missing description! Please add one in the manager.";
		}
		$('.slideDescription').html( '<p>' + slideDescription + '</p>');
		$('.slideDescription p').vAlign();// we center the description vertically
	}
});

// below are the click handlers for the previous & next buttons
$('#prev2').click(function(){
	//alert ($('#tdSlideShowNav li').index($('.activeSlide')));
	var currentSlideIndex = $('#tdSlideShowNav li').index($('.activeSlide'));
	if (currentSlideIndex>0) {
		$('#tdSlideShowNav li').removeClass();
		$('.tdSlideShow:visible').flexslider('prev');
		$('#tdSlideShowNav li:nth-child(' + currentSlideIndex +')').addClass('activeSlide');
		return false;
	};
	return false;
});
$('#next2').click(function(){
	var currentSlideIndex = $('#tdSlideShowNav li').index($('.activeSlide'));
	if (currentSlideIndex<5) {
		var nextSlideIndex = currentSlideIndex + 2;
		$('#tdSlideShowNav li').removeClass();
		$('.tdSlideShow:visible').flexslider('next');
		$('#tdSlideShowNav li:nth-child(' + nextSlideIndex +')').addClass('activeSlide');
		return false;
	};
	return false;
});

// and this part  is for the slideshow navigation
$('#tdSlideShowNav li a').each(function(index){
	$(this).click(function(){
		
		$(this).parent().addClass('activeSlide').siblings().removeClass();
		$('.tdSlideShow:visible').flexslider(index);
		return false;
	});
});
// end typical day page code


// prettyphotto
$("a[rel^='prettyPhoto']").prettyPhoto({
            deeplinking: false,
            default_width: 800,
            default_height: 450,
			social_tools: false /* html or false to disable */
		});

/* map */

$(document).ready(function(){
	var settings = {
		'viewportWidth' : '100%',
		'viewportHeight' : '100%',
		'fitToViewportShortSide' : true,  
		'contentSizeOver100' : false,
		'startScale' : 0,
		'startX' : 0,
		'startY' : 0,
		'animTime' : 500,
		'draggInertia' : 10,
		'imgDir' : '/cww-pw/site/templates/images/map/',
		'mainImgWidth' : 1683,
		'mainImgHeight' : 1129,
		'intNavEnable' : true,
		'intNavPos' : 'B',
		'intNavAutoHide' : false,
		'intNavMoveDownBtt' : true,
		'intNavMoveUpBtt' : true,
		'intNavMoveRightBtt' : true,
		'intNavMoveLeftBtt' : true,
		'intNavZoomBtt' : true,
		'intNavUnzoomBtt' : true,
		'intNavFitToViewportBtt' : true,
		'intNavFullSizeBtt' : true,
		'intNavBttSizeRation' : 1,
		'mapEnable' : true,
		'mapPos' : 'BL',
		'popupShowAction' : 'click',
		'testMode' : false
	};
	
	$('#interactiveMapHolder').lhpGigaImgViewer(settings, 'MyHotspots');
});

$(document).ready(function(){
	$(".mapPopup ul li img").click(function(){

			$( ".visibleSlide img" ).removeClass( "activeThumb" );
			$( ".visibleSlide .thumbs li img" ).addClass( "inactiveThumb" );
			var src = $(this).attr('data-bigImage');
			$(this).removeClass("inactiveThumb");
			$(this).addClass("activeThumb");
			$('.visibleSlide .mainImage img').attr("src", src);

		
	});
	$(".mapPopup .close").click(function(){
		$(".mapPopup").hide("slow");
		$( "div" ).removeClass( "visibleSlide" );
	});
});