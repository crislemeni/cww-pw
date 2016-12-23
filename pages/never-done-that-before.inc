	<div class="slideshowHolder neverDoneBefore">

		<div class="flex-viewport" style="overflow: hidden; position: relative;">
			<ul class="slides" style="width: 1400%; -webkit-transition-duration: 0s; transition-duration: 0s; -webkit-transform: translate3d(-3360px, 0px, 0px);">
			
				<?php foreach ($page->ndtb_slideshow as $slide): ?>
					
				<li class="neverDoneThatBeforeWrap clone" style="width: 840px; float: left; display: block;">
					<img src="<?= $slide->getCrop("slide_size")->url ?>" alt="<?= $slide->description ?>">
					<div class="ndbText">
						<p class="p1"><?= $slide->description ?></p>
					</div>
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
	<!-- end .slideshowHolder -->