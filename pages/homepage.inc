								<div class="slideshowHolder">
									<ul class="slides">
										<?php if (count($page->homepage_slideshow)>=1): ?>
										<?php foreach ($page->homepage_slideshow as $image): ?>
										<li><img src="<?= $image->getCrop("homepage_slide_size")->url ?>" width="900" alt="<?= $image->description ?>" /></li>
										<?php endforeach ?>	
										<?php else: ?>
										<li><img src="http://placehold.it/900x383&text=missing+images" width="900" alt="" /></li>
										<?php endif ?>
									</ul>	 
								</div>
								<!-- end .slideshowHolder -->

								<div class="underSlideshowLinks">
									<ul>
										<li class="watchOurVideo"><a href="videos.html"><img src="<?= $config->urls->templates ?>images/watchVideo.png" alt="Watch Our Video" /></a></li>
										<li class="seeATypicalDay"><a href="<?= $pages->get(1075)->url; ?>"><img src="<?= $config->urls->templates ?>images/seeTypicalDay.png" alt="See a Typical Day at Camp" /></a></li>
										<li class="viewOurInteractiveMap"><a href="<?= $pages->get(2921)->url; ?>" target="_blank"><img src="<?= $config->urls->templates ?>images/viewInteractiveMap.png" alt="View Our Interactive Map" /></a></li>
										<li class="viewOurPhotoGallery"><a href="<?= $pages->get(1081)->url; ?>"><img src="<?= $config->urls->templates ?>images/viewPhotoGallery.png" alt="View Our Photo Gallery" /></a></li>
									</ul>
								</div>
								<!-- end .underSlideshowLinks -->


								<div class="secondPart">

									<div class="daysRemainingHolder">
										<div class="daysToOpening">Days to Camp Opening</div>
										<div class="daysRemaining"><?php
											$calculation = (($page->countdown_date - time())/3600);
											$hours = (int)$calculation;
											$days  = (int)($hours/24);
											if ($days >= 0) { echo $days ; }else{echo "0";}
										?></div>
									</div>
									<!-- end .daysRemainingHolder -->

									<div class="textHolder">
										<?= $page->body ?>
									</div>
						 			<!-- /.textHolder -->
								</div>
								<!-- end .secondPart --> 