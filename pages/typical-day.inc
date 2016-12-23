<div class="tdSlideShowOuterWrap">
    <div class="tdTopWrapper">
		<ul class="genderSelector">
			<li><a href="#" id="b">Boy</a></li>
			<li><a href="#" id="g">Girl</a></li>
		</ul>

		<ul class="ageSelector">
            <li><a href="#" id="a78">7-8 <span>years</span></a></li>
			<li><a href="#" id="a911">9-11 <span>years</span></a></li>
			<li><a href="#" id="a1213">12-13 <span>years</span></a></li>
			<li><a href="#" id="a1415">14-15 <span>years</span></a></li>
		</ul>
	</div>
	<!-- end tdTopWrapper -->
	<div class="tdSlideShowWrap">

		<div class="welcomeMessage"><img src="/site/templates/images/typicalDay/typicalDayStart.jpg"></div>
    	<div class="ageError"><img src="/site/templates/images/typicalDay/typicalDayAgeError.jpg"></div>
		<div class="genderError"><img src="/site/templates/images/typicalDay/typicalDayGenderError.jpg"></div>

		<div class="tdSlideShow flexslider" id="slideShow-b-a78">
            <ul class="slides">
			<?php foreach ($page->td_b_age1 as $slide): ?>
			<li><img src="<?= $slide->getCrop("slide")->url ?>" alt="<?= $slide->description ?>" data-description="<?= $slide->description ?>"></li>
			<?php endforeach ?>
            </ul>
		</div>

		<div class="tdSlideShow flexslider" id="slideShow-b-a911">
            <ul class="slides">
			<?php foreach ($page->td_b_age2 as $slide): ?>
			<li><img src="<?= $slide->getCrop("slide")->url ?>" alt="<?= $slide->description ?>" data-description="<?= $slide->description ?>"></li>
			<?php endforeach ?>
            </ul>
		</div>

		<div class="tdSlideShow flexslider" id="slideShow-b-a1213">
            <ul class="slides">
			<?php foreach ($page->td_b_age3 as $slide): ?>
			<li><img src="<?= $slide->getCrop("slide")->url ?>" alt="<?= $slide->description ?>" data-description="<?= $slide->description ?>"></li>
			<?php endforeach ?>
            </ul>
		</div>
        
        <div class="tdSlideShow flexslider" id="slideShow-b-a1415">
            <ul class="slides">
    		<?php foreach ($page->td_b_age4 as $slide): ?>
			<li><img src="<?= $slide->getCrop("slide")->url ?>" alt="<?= $slide->description ?>" data-description="<?= $slide->description ?>"></li>
			<?php endforeach ?>
            </ul>
		</div>

		<div class="tdSlideShow flexslider" id="slideShow-g-a78">
            <ul class="slides">
			<?php foreach ($page->td_g_age1 as $slide): ?>
			<li><img src="<?= $slide->getCrop("slide")->url ?>" alt="<?= $slide->description ?>" data-description="<?= $slide->description ?>"></li>
			<?php endforeach ?>
            </ul>
		</div>

		<div class="tdSlideShow flexslider" id="slideShow-g-a911">
                <ul class="slides">
				<?php foreach ($page->td_g_age2 as $slide): ?>
			<li><img src="<?= $slide->getCrop("slide")->url ?>" alt="<?= $slide->description ?>" data-description="<?= $slide->description ?>"></li>
			<?php endforeach ?>
                </ul>
		</div>

		<div class="tdSlideShow flexslider" id="slideShow-g-a1213">
            <ul class="slides">
			<?php foreach ($page->td_g_age3 as $slide): ?>
			<li><img src="<?= $slide->getCrop("slide")->url ?>" alt="<?= $slide->description ?>" data-description="<?= $slide->description ?>"></li>
			<?php endforeach ?>
            </ul>
		</div>
        
        <div class="tdSlideShow flexslider" id="slideShow-g-a1415">
            <ul class="slides">
    		<?php foreach ($page->td_g_age4 as $slide): ?>
			<li><img src="<?= $slide->getCrop("slide")->url ?>" alt="<?= $slide->description ?>" data-description="<?= $slide->description ?>"></li>
			<?php endforeach ?>
            </ul>
		</div>

	</div>
	<!-- /.tdSlideShowWrap -->

	<div class="slideshowNavWrap">
		<div class="tdSlideshowNavCover">

		</div>
		<ul id="tdSlideShowNav" class="tdInactiveButtons">
			<li><a href="#"><span class="oneLine">Water-ski</span></a></li>
			<li><a href="#"><span>Ropes <span>Course</span></span></a></li>
			<li id="thirdButton"><a href="#"><span class="oneLine">Sports</span></a></li>
			<li><a href="#"><span class="oneLine">Arts</span></a></li>
			<li><a href="#"><span class="oneLine">Swim</span></a></li>
			<li class="last"><a href="#"><span>Special <span>Event</span></span></a></li>
		</ul>
	</div>
	<!-- /.slideshowNavWrap -->

	<div class="slideDescription">

	</div>
	<!-- end slideDescription -->


		<a href="#" id="prev2">prev</a>
		<a href="#" id="next2">next</a>
</div>
<!-- /.tdSlideShowOuterWrap -->