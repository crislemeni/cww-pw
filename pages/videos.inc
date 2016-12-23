        <div class="videoItem mainVideoItem">
  			<a href="<?= $page->video_main->video_url ?>" rel="prettyPhoto">
  			<img src="<?= $page->video_main->getCrop("big-thumbnail")->url ?>" alt="Living 10 for 2" width="600" height="313" />
  			<span><?= $page->video_main->caption ?></span></a>
		</div>
	<div class="videoItemsWrapper">

		<?php foreach ($page->videos as $video): ?>
			
		<div class="videoItem">
			<a href="<?= $video->video_url ?>" rel="prettyPhoto">
				<img src="<?= $video->getCrop("thumbnail")->url ?>" alt="<?= $video->caption ?>" width="230" height="120" />
				<span><?= $video->caption ?></span>
			</a>
		</div>

		<?php endforeach ?>
		
	</div>
	<!-- /.videoItemsWrapper -->

	<div style="clear: both;"></div>