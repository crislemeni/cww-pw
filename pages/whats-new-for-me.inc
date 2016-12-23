	<div class="innerPageImgHolder">
		<img src="<?= $page->banner_image ? $page->banner_image->getCrop("banner_size")->url : 
		"http://placehold.it/620x270&text=missing+image" ?>" width="620" height="270" alt="<?= $page->banner_image->description ?>" />
		<?php if ($page->id == "1018"): ?>
		<a href="videos.html" class="watchVideoInnerUpper">Watch Our Video</a>	
		<?php endif ?>
		<h3><?= $page->get("headline|title") ?></h3>
	</div>
	<!-- /.innerPageImgHolder -->

	<div class="innerPageRTE">
		<?= $page->body; ?>
	</div>
	<!-- /.innerPageRTE -->


		<div class="whatsNewHeader">
			<h2 class="heading01">New at CWW</h2> <h2 class="heading02">New for Me</h2>
			<ul class="slideshowSelection">
				<li class="line"></li>
				<li class="newInGeneral"><a href="#" class="active">show me the highlights</a></li>
				<li class="newAgeGroup1"><a href="#" class="">Junior Camp</a></li>
				<li class="newAgeGroup2"><a href="#" class="">Upper Camp</a></li>
				<li class="newAgeGroup3"><a href="#" class="">Senior Camp</a></li>
				<li class="newAgeGroup4"><a href="#" class="">Middle Camp</a></li>
			</ul>
		</div>
		<!-- /.whatsNewHeader -->

		<div class="whatsNewSlideWrapper" id="newInGeneral" style="display: block;">
			<div class="whatsNew">
				<ul class="whatsNewSlidesow slides">
					<?php foreach ($page->wn_highlights_slides as $slide): ?>
						<li class="clone">
							<img src="<?= $slide->getCrop("slide_size")->url ?>" alt="<?= $slide->description ?>">
						</li>
					<?php endforeach ?> 
				</ul>
			</div>
			<ul class="whatsNewPager"></ul>
			<div class="whatsNewTextContent">
				<h2 class="heading01">What’s new this summer at CWW</h2>
				<div class="whatIsNewThisSummerContent">
						 <?= $page->wn_highlights_content ?>
				</div>
				<!-- /.whatIsNewThisSummerContent -->
			</div>
			<!-- /.whatsNewTextContent -->
		</div>
		<!--end .whatsNewSlideWrapper-->



		<!-- START AGE GROUP 1 -->
		<div class="whatsNewSlideWrapper" id="newAgeGroup1" style="display: none;">

			<div class="whatsNew">
			 		<div class="flex-viewport">

					<ul class="whatsNewSlidesow slides" >
						<?php foreach ($page->wn_ag1_slides as $slide): ?>
						<li class="clone">
							<img src="<?= $slide->getCrop("slide_size")->url ?>" alt="<?= $slide->description ?>">
						</li>
						<?php endforeach ?>
					</ul>

				</div>
				<!-- /.flex-viewport -->

				<ul class="flex-direction-nav">
					<li><a class="flex-prev" href="#">Previous</a></li>
					<li><a class="flex-next" href="#">Next</a></li>
				</ul>
			</div>
			<!-- /.whatsNew -->


			<ul class="whatsNewPager"></ul>

			<div class="whatsNewTextContent">
				<h2 class="heading01">What’s new this summer for Junior Camp</h2>
				<div class="whatIsNewThisSummerContent">
					<?= $page->wn_ag1_content ?>
				</div>
				<!-- /.whatIsNewThisSummerContent -->
			</div>
			<!-- /.whatsNewTextContent -->
		</div>
		<!--end .whatsNewSlideWrapper-->
		<!-- END AGE GROUP 1 -->

		<!-- START AGE GROUP 2 -->
		<div class="whatsNewSlideWrapper" id="newAgeGroup2" style="display: none;">

			<div class="whatsNew">
			 		<div class="flex-viewport">

					<ul class="whatsNewSlidesow slides" >
						<?php foreach ($page->wn_ag2_slides as $slide): ?>
						<li class="clone">
							<img src="<?= $slide->getCrop("slide_size")->url ?>" alt="<?= $slide->description ?>">
						</li>
						<?php endforeach ?>
					</ul>

				</div>
				<!-- /.flex-viewport -->

				<ul class="flex-direction-nav">
					<li><a class="flex-prev" href="#">Previous</a></li>
					<li><a class="flex-next" href="#">Next</a></li>
				</ul>
			</div>
			<!-- /.whatsNew -->


			<ul class="whatsNewPager"></ul>

			<div class="whatsNewTextContent">
				<h2 class="heading01">What’s new this summer for Junior Camp</h2>
				<div class="whatIsNewThisSummerContent">
					<?= $page->wn_ag2_content ?>
				</div>
				<!-- /.whatIsNewThisSummerContent -->
			</div>
			<!-- /.whatsNewTextContent -->
		</div>
		<!--end .whatsNewSlideWrapper-->
		<!-- END AGE GROUP 2 -->

		<!-- START AGE GROUP 3 -->
		<div class="whatsNewSlideWrapper" id="newAgeGroup3" style="display: none;">

			<div class="whatsNew">
			 		<div class="flex-viewport">

					<ul class="whatsNewSlidesow slides" >
						<?php foreach ($page->wn_ag3_slides as $slide): ?>
						<li class="clone">
							<img src="<?= $slide->getCrop("slide_size")->url ?>" alt="<?= $slide->description ?>">
						</li>
						<?php endforeach ?>
					</ul>

				</div>
				<!-- /.flex-viewport -->

				<ul class="flex-direction-nav">
					<li><a class="flex-prev" href="#">Previous</a></li>
					<li><a class="flex-next" href="#">Next</a></li>
				</ul>
			</div>
			<!-- /.whatsNew -->


			<ul class="whatsNewPager"></ul>

			<div class="whatsNewTextContent">
				<h2 class="heading01">What’s new this summer for Junior Camp</h2>
				<div class="whatIsNewThisSummerContent">
					<?= $page->wn_ag3_content ?>
				</div>
				<!-- /.whatIsNewThisSummerContent -->
			</div>
			<!-- /.whatsNewTextContent -->
		</div>
		<!--end .whatsNewSlideWrapper-->
		<!-- END AGE GROUP 3 -->

		<!-- START AGE GROUP 4 -->
		<div class="whatsNewSlideWrapper" id="newAgeGroup4" style="display: none;">

			<div class="whatsNew">
			 		<div class="flex-viewport">

					<ul class="whatsNewSlidesow slides" >
						<?php foreach ($page->wn_ag4_slides as $slide): ?>
						<li class="clone">
							<img src="<?= $slide->getCrop("slide_size")->url ?>" alt="<?= $slide->description ?>">
						</li>
						<?php endforeach ?>
					</ul>

				</div>
				<!-- /.flex-viewport -->

				<ul class="flex-direction-nav">
					<li><a class="flex-prev" href="#">Previous</a></li>
					<li><a class="flex-next" href="#">Next</a></li>
				</ul>
			</div>
			<!-- /.whatsNew -->


			<ul class="whatsNewPager"></ul>

			<div class="whatsNewTextContent">
				<h2 class="heading01">What’s new this summer for Junior Camp</h2>
				<div class="whatIsNewThisSummerContent">
					<?= $page->wn_ag4_content ?>
				</div>
				<!-- /.whatIsNewThisSummerContent -->
			</div>
			<!-- /.whatsNewTextContent -->
		</div>
		<!--end .whatsNewSlideWrapper-->
		<!-- END AGE GROUP 4 -->