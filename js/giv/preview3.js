$(document).ready(function(){
	var pluginMethods;
	
	var settings = {
		'viewportWidth' : '100%',
		'viewportHeight' : '100%',
		'fitToViewportShortSide' : false,  
		'contentSizeOver100' : false,
		'startScale' : .5,
		'startX' : 1860,
		'startY' : 2830,
		'animTime' : 500,
		'draggInertia' : 10,
		'imgDir' : 'hubbleImgSrc/',
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
	
	$('#myDiv').lhpGigaImgViewer(settings);
	
	pluginMethods = [];
	pluginMethods[0] = function(){ $('#myDiv').lhpGigaImgViewer( settings ); };
	pluginMethods[1] = function(){ $('#myDiv').lhpGigaImgViewer( 'setPosition', 1300, 700, 0.8, false ); };
	pluginMethods[2] = function(){ $('#myDiv').lhpGigaImgViewer( 'moveUp' ); };
	pluginMethods[3] = function(){ $('#myDiv').lhpGigaImgViewer( 'moveDown' ); };
	pluginMethods[4] = function(){ $('#myDiv').lhpGigaImgViewer( 'moveLeft' ); };
	pluginMethods[5] = function(){ $('#myDiv').lhpGigaImgViewer( 'moveRight' ); };
	pluginMethods[6] = function(){ $('#myDiv').lhpGigaImgViewer( 'moveStop' ); };
	pluginMethods[7] = function(){ $('#myDiv').lhpGigaImgViewer( 'zoom' ); };
	pluginMethods[8] = function(){ $('#myDiv').lhpGigaImgViewer( 'unzoom' ); };
	pluginMethods[9] = function(){ $('#myDiv').lhpGigaImgViewer( 'zoomStop' ); };
	pluginMethods[10] = function(){ $('#myDiv').lhpGigaImgViewer( 'fitToViewport' ); };
	pluginMethods[11] = function(){ $('#myDiv').lhpGigaImgViewer( 'fullSize' ); };
	pluginMethods[12] = function(){ $('#myDiv').lhpGigaImgViewer( 'adaptsToContainer' ); };
	pluginMethods[13] = function(){ $('#myDiv').lhpGigaImgViewer( 'destroy' ); };
	pluginMethods[14] = function(){ return $('#myDiv').lhpGigaImgViewer( 'getCurrentState' ); };
	
	$('#myDiv').lhpGigaImgViewer(settings);
	
	$('#publicMethods a').each(function(index){
		
		$(this).click(function(index) {
				return function(e) {
					e.preventDefault();	
					if(index == 14) {
						displayCurrentState(pluginMethods[index]());
					} else {
						pluginMethods[index]();
					}
				}
			}(index));

	});
	
	function displayCurrentState(currentState) {
		var res = '';
		
		res += 'scale : ' + currentState.scale; 
		res += '<br/>xPosInCenter : ' + currentState.xPosInCenter; 
		res += '<br/>yPosInCenter : ' + currentState.yPosInCenter;
		res += '<br/>allowDown : ' + currentState.allowDown; 
		res += '<br/>allowUp : ' + currentState.allowUp; 
		res += '<br/>allowLeft : ' + currentState.allowLeft; 
		res += '<br/>allowRight : ' + currentState.allowRight; 
		res += '<br/>allowZoom : ' + currentState.allowZoom; 
		res += '<br/>allowUnzoom : ' + currentState.allowUnzoom; 
		res += '<br/>hPropViewpContent : ' + currentState.hPropViewpContent; 
		res += '<br/>wPropViewpContent : ' + currentState.wPropViewpContent; 
		res += '<br/>isScaled : ' + currentState.isScaled; 
		
		$('#currentStates').html(res);
	}
});