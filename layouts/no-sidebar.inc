<div class="pageContent singleColumn<?= $page->template == "never-done-that-before" ? " ndtb-page" : "" ?>">
	<h1><?= $page->get("headline|title") ?></h1>
	<?= $page->body ?>
	
	<?php require($config->paths->templates."pages/".$layoutContent); ?>

</div>
<!-- /.pageContent .singleColumn -->