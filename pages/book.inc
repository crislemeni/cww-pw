	<div class="innerPageImgHolder">
		<img src="<?= $page->banner_image ? $page->banner_image->getThumb("banner_size") : 
		"http://placehold.it/620x270&text=missing+image" ?>" width="620" height="270" alt="<?= $page->banner_image->description ?>" />
		<?php if ($page->id == "1018"): ?>
		<a href="videos.html" class="watchVideoInnerUpper">Watch Our Video</a>	
		<?php endif ?>
		<h3><?= $page->get("headline|title") ?></h3>
	</div>

	
	<div class="innerPageRTE">
	<?= $page->body; ?>
	<?php if (count($page->children)): ?>
	<ul>
	<?php foreach ($page->children as $link): ?>
	<li><a href="<?= $link->httpUrl ?>"><?= $link->title ?></a></li>
	<?php endforeach ?>
	</ul>
	<?php endif ?>
	</div>