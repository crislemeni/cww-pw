<?php 

	//  PARENT LOGIN 
	if ($page == $pages->get("1097") || $pages->get("1097")->children->has($page) ) { require("./includes/summer-login-logic.inc");}

	//  alumni LOGIN 
	if ($page == $pages->get("1093") || $pages->get("1093")->children->has($page) ) { require("./includes/alumni-login-logic.inc");}
?>
<?php //$session->remove("parentLoggedIn"); ?>
<!DOCTYPE html>
<html>
<head>
		<title>Overnight Summer Camp for Kids in the Mountains of New Hampshire | Camp Walt Whitman</title>
		<!-- <base href="http://www.campwalt.com/" /> -->
		<meta name="keywords" content="overnight summer camp for kids" />
		<meta name="description" content="Camp Walt Whitman is an overnight summer camp for kids in the White Mountains of New Hampshire. Sports, swimming, arts and adventure in a safe and beautiful environment." />
		<link rel="author" href="https://plus.Google.com/u/0/114045420858316303532/" />
		<meta name="p:domain_verify" content="c63e4f29829b4404a1150d4945d7bd5b"/>
		<meta name="viewport" content="width=device-width, maximum-scale=1.0, initial-scale=1,	user-scalable=1"/>
		<link href='https://fonts.googleapis.com/css?family=Roboto+Condensed:400,400italic,700,700italic|Skranji' rel='stylesheet' type='text/css' />
		<link rel="stylesheet" media="all" type="text/css" href="<?= $config->urls->templates ?>css/style.css?v=1004" />
		<link rel="stylesheet" media="all" type="text/css" href="<?= $config->urls->templates ?>css/flexslider.css" />
		<link type="text/css" rel="stylesheet" href="<?= $config->urls->templates ?>css/eventscalendar2/default.css"/>

		<?php 
		echo '
		<!-- style sheets -->
		<!-- <link rel="stylesheet" type="text/css" href="css/reset.css" /> -->
		<link rel="stylesheet" type="text/css" href="'.$config->urls->templates.'css/giv/main.css" />
		<!-- ColorBox css -->
		<link rel="stylesheet" type="text/css" href="'.$config->urls->templates.'css/giv/colorbox.css" />
		<!-- jQuery ThemeRoller -->
		<link rel="stylesheet" type="text/css" href="'.$config->urls->templates.'css/giv/custom-theme/jquery-ui-1.10.3.custom.css" />
		<!-- lhpGigaImgViewer plugin css -->
		<link rel="stylesheet" type="text/css" href="'.$config->urls->templates.'css/giv/lhp_giv.css" />
		';
	?>
	 
		<script src="<?= $config->urls->templates ?>js/modernizr-2.6.2.min.js"></script>
		<link type="text/css" rel="stylesheet" href="<?= $config->urls->templates ?>css/prettyPhoto.css"/>
		<meta name="geo.region" content="US-NH" />
		<meta name="geo.placename" content="Piermont" />
		<meta name="geo.position" content="43.950417;-71.964427" />
		<meta name="ICBM" content="43.950417, -71.964427" />
		<!--[if IE]>
		<style>
		.messageFromDirectors {
				background: none;
				filter:progid:DXImageTransform.Microsoft.AlphaImageLoader(src='/assets/images/messageFromDirectors.png', sizingMethod='scale');
		}
		.leftColumnInner .quickLinks {
				background: none;
			filter:progid:DXImageTransform.Microsoft.AlphaImageLoader(src='/assets/images/sidebarQuickLinks.gif', sizingMethod='scale');
		}
		.leftColumnInner .watchVideoInner a {
				background: none;
			filter:progid:DXImageTransform.Microsoft.AlphaImageLoader(src='/assets/images/watchOurVideoInner.png', sizingMethod='scale');
		}
		</style>
		<![endif]-->
		 
</head>
<body id="index" class="page1">

<div class="bodyBgRepeat">
	<div class="mainWrapper">
		<div class="bgTopRepeat">
			<div class="darkTop">
				<div class="ieFix">
					<div class="grassBottom">

						<div class="header">
							
							<a href="http://www.campwalt.com/" class="logo"><img src="<?= $config->urls->templates ?>images/logo.png" width="308" height="123" alt="Camp Walt Whitman" /></a>
							
							<div class="phoneInfo">(800) 657-8282 | 

							<?php 
							$topMenuNoItems = count($pages->get("1")->top_menu); $i = 0;
							foreach ($pages->get("1")->top_menu as $key => $item): 
								$endString = (++$i === $topMenuNoItems) ? "" : " | "; 
								$class = ($item->id == "2616") ? " class='contactLinkHeader' " : "";

							?>
							<a href="<?= $item->get("gallery_url|httpUrl") ?>"<?= $class ?>><?= $item->title ?></a><?= $endString ?>
							<?php endforeach ?>

							</div>
							<!-- /.phoneInfo -->

							<div class="messageFromDirectors"><a href="http://www.campwalt.com/message-from-our-directors.html" target="_blank">A Message from our Directors</a></div>
							<div class="navigationMain">
								<ul>
									<?php foreach ($pages->get("1")->main_menu->prepend($pages->get("1")) as $item): ?>
									<?php $class = ($page->rootParent->id == $item->id) ? " class='active'" : ""; ?>
									<li <?= $class ?>><a href="<?= $item->url ?>" title="<?= $item->title ?>"><?= $item->title ?></a></li>
									<?php endforeach ?>
									
								</ul>
		
								<div class="enroll">
									<a class="requestInfo" href="request-info.html">Request Info</a>
									<a class="enrollNow" href="request-info.html">Enroll Now</a>
								</div>
							</div>
							<!-- /.navigationMain -->
		
						</div>
						<!-- end header -->

						<div class="contentWrapper">
							<div class="contentPage">

							<?php switch ($page->template) {
								case 'home':
									require("./pages/homepage.inc");
									break;
								case 'basic-page':
									$layoutContent = "basic-page.inc";
									require("./layouts/sidebar-left.inc");
									break;
								case 'interactive-map':
									$layoutContent = "interactive-map.inc";
									require("./layouts/no-sidebar.inc");
									break;
								case 'never-done-that-before':
									$layoutContent = "never-done-that-before.inc";
									require("./layouts/no-sidebar.inc");
									break;
								case 'whats-new-for-me':
									$layoutContent = "whats-new-for-me.inc";
									require("./layouts/sidebar-left.inc");
									break;
								case 'book':
									$layoutContent = "book.inc";
									require("./layouts/sidebar-left.inc");
									break;
								case 'book-page':
									$layoutContent = "basic-page.inc";
									require("./layouts/sidebar-left.inc");
									break;
								case 'typical-day':
									$layoutContent = "typical-day.inc";
									require("./layouts/no-sidebar.inc");
									break;
								case 'alumni-login':
									$layoutContent = "alumni-login.inc";
									require("./layouts/sidebar-left.inc");
									break;
								case 'alumni-notes':
									$layoutContent = "alumni-notes.inc";
									require("./layouts/sidebar-left.inc");
									break;
								case 'calendar':
									$layoutContent = "calendar.inc";
									require("./layouts/no-sidebar.inc");
									break;
								case 'parent-login':
									$layoutContent = "parent-login.inc";
									require("./layouts/no-sidebar.inc");
									break;
								case 'videos':
									$layoutContent = "videos.inc";
									require("./layouts/no-sidebar.inc");
									break;
								default:
									# code...
									break;
							} ?>

							</div>
							<!-- end content --> 

							<div class="socialmediaContainer">
								<div class="accreditedHolder"><a href="http://www.acacamps.org/" class="ACAaccredited" target="_blank">ACA accredited</a></div>
								<div class="socialMediaLinks">
									<a href="http://www.youtube.com/user/CampWalt" class="youtube" target="_blank">Youtube</a>
									<a href="http://twitter.com/campwaltwhitman" class="twitter" target="_blank">Twitter</a>
									<a href="http://www.facebook.com/CampWaltWhitman" class="facebook" target="_blank">Facebook</a>
									<a class="plusOne" href="https://plus.google.com/u/0/101287043477240348581/posts" target="_blank">Google +</a>
									<!-- 	<script type="text/javascript" src="https://apis.google.com/js/plusone.js"></script>
									<g:plusone></g:plusone> -->	
						
								</div>
								<!-- end .contentWrapper --> 
							</div>
							<!-- end .socialmediaContainer --> 
						</div>
						<!-- /.contentWrapper -->

						<div class="smallTree"></div>
						<div class="bigTree"></div>
			
					</div>
					<!-- /.grassBottom --> 
				</div>
				<!-- /.ieFix --> 
			</div>
			<!-- .darkTop -->
		</div>
		<!-- .bgTopRepeat -->
	</div>
	<!-- /.mainWrapper -->
</div>
<!-- /.bodyBgRepeat -->


<div class="footer">
	<div class="footerInside">

		<div class="column">
			<ul>
				<li><a href="http://www.campwalt.com/">Home</a></li>
				<li><a href="about-us.html">About Us</a></li>
				<li><a href="future-families.html">Future Families</a></li>
				<li><a href="current-families.html">Current Families</a></li>
				<li><a href="staff.html">Staff</a></li>
			</ul>
		</div>
		<!-- /.column -->

		<div class="column">
			<ul>
				<li><a href="alumni.html">Alumni</a></li>
				<li><a href="contact.html">Contact Us</a></li>
				<li><a href="terms-and-conditions.html">Terms and Conditions</a></li>
				<li><a href="site-map.html">Sitemap</a></li>
			</ul>
		</div>

		<div class="column" id="addressColumn">
			<div id="" class="vcard">
 				<a class="url fn n" href="http://www.campwalt.com">
 					<span class="given-name"></span>
					<span class="additional-name"></span>
					<span class="family-name"></span>
				</a>
 				<div class="org">Camp Walt Whitman</div>
 				<a class="email" href="mailto:cww@campwalt.com">cww@campwalt.com</a>
 				<div class="adr">
					<div class="street-address">1000 Cape Moonshine Road</div>
					<span class="locality">Piermont</span>, <span class="region">New Hampshire</span>, <span class="postal-code">03779</span> <span class="country-name">United States</span>
 				</div>
 				<div class="tel">(603) 764-5521, (914) 948-9151</div>
			</div>
			<!-- /.vcard -->
		</div>
		<!-- /.column -->

			<p class="copyright">© 2015 Copyright Info. All rights reserved.</p>
			<p class="copyright siteBy"><a href="http://www.dvscampmarketing.com/" target="_blank">Camp website by DVS Camp Marketing</a></p>
	</div>
	<!-- /.footerInside -->
</div>
<!-- /.footer -->

<?php 

	// If the page is editable, then output a link that takes us straight to the page edit screen:
	if($page->editable()) {
		echo "<a style='position:absolute;top:0;left:0;background-color:#FF0090;color:white;padding:10px;z-index:999;' href='{$config->urls->admin}page/edit/?id={$page->id}'>Edit in back-end</a>"; 
	}

?>

<!-- CLOSE all html-elements (+wrapper) before this line -->

<script src="<?= $config->urls->templates ?>/js/jquery-1.9.1.min.js"></script>
<!-- <script>window.jQuery || document.write('<script src="http://www.campwalt.com/assets/js/libs/jquery-1.7.1.min.js"><\/script>')</script> -->

<script src="<?= $config->urls->templates ?>js/plugins.js"></script>
<script src="<?= $config->urls->templates ?>js/jquery.flexslider-min.js"></script>
<script src="<?= $config->urls->templates ?>js/scripts.js"></script>
<?php if ($page->id == "1096"): ?>
<script src="<?= $config->urls->templates ?>js/calendar-ajax.js"></script>
<?php endif ?>

<?php if ($page->template == "interactive-map"): ?>
	<!-- giv js files -->
	<!-- js files -->
		
		<!-- jQuery easing plugin-->
		<script type="text/javascript" src="<?= $config->urls->templates ?>scripts/giv/jquery.easing.1.3.js"></script>
		<!-- jQuery mousewheel plugin-->
		<script type="text/javascript" src="<?= $config->urls->templates ?>scripts/giv/jquery.mousewheel.min.js"></script>
		<!-- lhpGigaImgViewer plugin -->
		<script type="text/javascript" src="<?= $config->urls->templates ?>scripts/giv/jquery.lhpGigaImgViewer.js"></script>

		<script>
			
	</script>
	<!-- swfobject -->
	<script  src="<?= $config->urls->templates ?>scripts/giv/swfobject.js"></script>

<?php endif ?>

<script type="text/javascript">

	// var _gaq = _gaq || [];
	// _gaq.push(['_setAccount', 'UA-433272-7']);
	// _gaq.push(['_trackPageview']);

	// (function() {
	// 	var ga = document.createElement('script'); ga.type = 'text/javascript'; ga.async = true;
	// 	ga.src = ('https:' == document.location.protocol ? 'https://ssl' : 'http://www') + '.google-analytics.com/ga.js';
	// 	var s = document.getElementsByTagName('script')[0]; s.parentNode.insertBefore(ga, s);
	// })();

</script>

<script type="text/javascript">
	 // var _mfq = _mfq || [];
	 // (function() {
		// 	 var mf = document.createElement("script"); mf.type = "text/javascript"; mf.async = true;
		// 	 mf.src = "//cdn.mouseflow.com/projects/c069df5f-191b-4cb3-9362-2ea8fe99741a.js";
		// 	 document.getElementsByTagName("head")[0].appendChild(mf);
	 // })();
</script>

</body>
</html>