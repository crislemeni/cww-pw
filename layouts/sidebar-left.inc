<div class="leftColumnInner">

	<div id="showSubmenu">Select a page:</div>
	<div class="sidebarHolder">
			<div class="sidebar">
			
			<?php
				$sideMenuOptions = array(
					'current_class' => 'active',					
					'item_tpl' => '<a href="{url}" title="{title}"><span class="outer"><span class="inner">{title}</span></span></a>',
					'item_current_tpl' => '<a href="{url}" title="{title}"><span class="outer"><span class="inner">{title}</span></span></a>',
					'firstlast' => true,
					'parent_class' => 'active',
					'has_children_class' => '',
					'max_levels' => 2,
					 "selector_level2" => "template!=book-page"
					);
				$treeMenu = $modules->get("MarkupSimpleNavigation"); // load the module
				echo $treeMenu->render($sideMenuOptions, null, $page->rootParent); // render default menu
			?>
			
		</div>
		<!-- end sidebar -->
	</div>
	<!-- /.sidebarHolder -->

	<div class="watchVideoInner"><a href="<?= $pages->get("2846")->httpUrl ?>">Watch Our Video</a></div>
	
	<div class="quickLinks">
		<ul>
			<li class="typicalDayInner"><a href="<?= $pages->get(1075)->url; ?>">See a Typical Day</a></li>
			<li class="takeVirtualTourInner"><a href="<?= $pages->get(2921)->url; ?>" target="_blank">Take a Virtual Tour</a></li>
			<li class="viewPhotosInner"><a href="<?= $pages->get(1081)->url; ?>">View Our Photos</a></li>
		</ul>
	</div>
	<!-- /.quickLinks -->
</div>
<!-- /.leftColumnInner -->

<div class="quickLinksBar"></div>
<div class="quickLinksBar02"></div>

<div class="pageContent">
<?php require($config->paths->templates."pages/".$layoutContent); ?>
</div>
<!-- /.pageContent -->

<div style="clear: both;"></div>