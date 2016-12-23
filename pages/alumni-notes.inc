	<div class="innerPageImgHolder">

			<img src="<?= $page->banner_image ? $page->banner_image->getThumb("banner_size") : 
			"http://placehold.it/620x270&text=missing+image" ?>" width="620" height="270" alt="<?= $page->banner_image->description ?>" />
			
			<h3><?= $page->get("headline|title") ?></h3>

		</div>
		<!-- /.innerPageImgHolder -->

		<div class="innerPageRTE">

			<?php echo $page->body;  ?>
		
		</div>
		<!-- /.innerPageRTE -->

		<div id="alumniNotes">

		<?php foreach ($page->children as $key => $years): ?>
			<h3 id="alumniHeading-<?= $years->name ?>" class="faq_question">
				<a href="#"><?= $years->title ?></a>
			</h3>
			<div class="faq_answer" style="display:none">
				<h2><?= $years->headline ?></h2>

				<?php foreach ($years->children as $key => $testimonial): ?>
				<p><a href="#alumni<?= $years->name ?>-<?= $key+1 ?>" rel="prettyPhoto"><?= $testimonial->title ?></a></p>
				<div id="alumni<?= $years->name ?>-<?= $key+1 ?>" class="hide">
					<h4 class="alumniNotesHeading"><?= $testimonial->title ?> writes:</h4>
					<div class="alumniNoteContent">
						<?= $testimonial->body_small ?>
						<p>My e-mail is: <a href="mailto:<?= $testimonial->email ?>"><?= $testimonial->email ?></a></p>
					</div>
				</div>
				<?php endforeach ?>

			</div>
			<!-- /.faq_answer -->
		<?php endforeach ?>

		</div>
		<!-- /.alumniNotes -->