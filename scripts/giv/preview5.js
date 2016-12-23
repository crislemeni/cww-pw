$(document).ready(function(){
	var $cbImgViewerCnt;
	
	var settings = {
		'viewportWidth' : '100%',
		'viewportHeight' : '100%',
		'fitToViewportShortSide' : true,  
		'contentSizeOver100' : false,
		'startScale' : 0,
		'startX' : 0,
		'startY' : 0,
		'animTime' : 500,
		'draggInertia' : 10,
		'imgDir' : 'sampleImgSrc_1/',
		'mainImgWidth' : 5000,
		'mainImgHeight' : 5000,
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
	
	$(".group1").colorbox({innerWidth : '600px', innerHeight : '400px', rel : 'group1'});
	$(".group1").colorbox({
		onComplete : function() {
			if($cbImgViewerCnt) {
				$cbImgViewerCnt.lhpGigaImgViewer('destroy');
			}
			$cbImgViewerCnt = $('<div/>').css({'width' : '100%', 'height' : '100%', 'overflow' : 'hidden'});
			$('#cboxLoadedContent').empty().append($cbImgViewerCnt);
			
			settings.imgDir = $(this).attr('href');
			settings.mainImgWidth = $(this).data('main-img-width');
			settings.mainImgHeight = $(this).data('main-img-height');
			
			$cbImgViewerCnt.lhpGigaImgViewer(settings);
		},
		onClosed : function() {
			if($cbImgViewerCnt) {
				$cbImgViewerCnt.lhpGigaImgViewer('destroy');
			}
		}
	});
	$('.sample img').each(function(index){
		$(this).hover(function(){
			$(this).stop(true, true).animate({'opacity':.4});
		},
		function () {
			$(this).stop(true, true).animate({'opacity':1});
		});
	});
});