$(document).ready(function(){
	var settings = {
		'viewportWidth' : '100%',
		'viewportHeight' : '100%',
		'fitToViewportShortSide' : false,  
		'contentSizeOver100' : false,
		'startScale' : 0,
		'startX' : 0,
		'startY' : 0,
		'animTime' : 500,
		'draggInertia' : 10,
		'imgDir' : 'sampleImgSrc_1/',
		'mainImgWidth' : 2000,
		'mainImgHeight' : 1346,
		'intNavEnable' : true,
		'intNavPos' : 'B',
		'intNavAutoHide' : false,
		'intNavMoveDownBtt' : true,
		'intNavMoveUpBtt' : true,
		'intNavMoveRightBtt' : true,
		'intNavMoveLeftBtt' : true,
		'intNavZoomBtt' : true,
		'intNavUnzoomBtt' : true,
		'intNavFitToViewportBtt' : true,
		'intNavFullSizeBtt' : true,
		'intNavBttSizeRation' : 1,
		'mapEnable' : true,
		'mapPos' : 'BL',
		'popupShowAction' : 'click',
		'testMode' : false
	};
	
	$('#myDiv').lhpGigaImgViewer(settings);
	
	$('#galleryThumbImg a').each(function(index){
		$(this).click(function(e) {
			e.preventDefault();
			
			settings.imgDir = $(this).attr('href');
			settings.mainImgWidth = $(this).data('main-img-width');
			settings.mainImgHeight = $(this).data('main-img-height');
			
			$('#myDiv').lhpGigaImgViewer('destroy');
			$('#myDiv').lhpGigaImgViewer(settings);
		});
	});
	$('#galleryThumbImg img').each(function(index){
		$(this).hover(function(){
			$(this).stop(true, true).animate({'opacity':.4});
		},
		function () {
			$(this).stop(true, true).animate({'opacity':1});
		});
	});
});