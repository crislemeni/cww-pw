	<div class="innerPageImgHolder">
		<?php if ($page->parent->template == "book"): ?>
		<img src="<?= $page->parent->banner_image ? $page->parent->banner_image->getCrop("banner_size")->url : 
		$config->urls->templates."images/innerPageImg.jpg" ?>" width="620" height="270" alt="<?= $page->parent->banner_image->description ?>" />
		<?php else: ?>
		<img src="<?= $page->banner_image ? $page->banner_image->getCrop("banner_size")->url : 
		$config->urls->templates."images/innerPageImg.jpg" ?>" width="620" height="270" alt="<?= $page->banner_image->description ?>" />
		<?php endif ?>
		
		<?php if ($page->id == "1018"): ?>
		<a href="videos.html" class="watchVideoInnerUpper">Watch Our Video</a>
		<?php endif ?>
		<h3><?= $page->get("headline|title") ?></h3>
	</div>

	
	<div class="innerPageRTE">
	<?= $page->body; ?>
	<?php if ($page->template == "book-page"): ?>
		<?php if ($page->parent->id == "1065"): ?>
	<a href="/current-families/cww-songbook/">back to Songbook</a>
		<?php else: ?>
	<a href="/current-families/cww-cookbook/">back to Cookbook</a>
		<?php endif ?>
	<?php endif ?>
	<?php if (count($page->faqs)): ?>
	<?php foreach ($page->faqs as $faq): ?>
	<h3 class="faq_question"><a href="#"><?= $faq->title ?></a></h3>
	<div class="faq_answer" style="display: block;"><?= $faq->body_small ?></div>
	<?php endforeach ?>
	<?php endif ?>
	</div>