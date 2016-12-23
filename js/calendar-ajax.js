$(window).load(function(){

	$.ajax({
		type: "GET",
		url: "/ajaxcalendar/",
		data: { },
		success: function(data){
		    $('#calendarHolder').html(data);
		}
    });

    $(document).on( "click", ".month a", function(event) {
    	event.preventDefault();
		//alert( $(this).attr("href") );  // jQuery 1.7+
		$.ajax({
			type: "GET",
			url: $(this).attr("href"),
			data: { },
			success: function(data){
			    $('#calendarHolder').html(data);
			}
    	});
	});
    
});