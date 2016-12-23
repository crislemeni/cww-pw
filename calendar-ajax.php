<?php
function renderCalendar($pages, $year, $month, $field = 'event_date') {

    date_default_timezone_set('America/New_York');

    // This feels little dirty, there is probably much more efficient way to get local day name?
    $mon = strftime('%a', strtotime("2011-11-14 00:00:00"));
    $tue = strftime('%a', strtotime("2011-11-15 00:00:00"));
    $wed = strftime('%a', strtotime("2011-11-16 00:00:00"));
    $thu = strftime('%a', strtotime("2011-11-17 00:00:00"));
    $fri = strftime('%a', strtotime("2011-11-18 00:00:00"));
    $sat = strftime('%a', strtotime("2011-11-19 00:00:00"));
    $sun = strftime('%a', strtotime("2011-11-20 00:00:00"));

    $year = (int) $year;
    $month = (int) $month;

    $startTime = strtotime("$year-$month-01 00:00:00");
    $endTime = strtotime("+1 month", $startTime);
    $lastMonth = strtotime("-1 month", $startTime);

    // find all events that fall in the given month and year

    $eventsPage = $pages->get("name=$year");// get the events folder corresponding to the selected year
    $events = $eventsPage->children("$field>=$startTime,$field<$endTime");

    // get all the info you need to draw a grid calendar
    $weekDayNames = array( $sun, $mon, $tue, $wed, $thu, $fri, $sat);
    $firstDayName = strftime('%a', $startTime); // i.e. "Tue" (Eng) or "ti" (Fin)
    $daysInMonth = date('t', $startTime); // 28 through 31

    // make the calendar headline
   
    $out = "<div class='month'>";
    $out .= "<a class='prev' href='/ajaxcalendar/". date('Y', $lastMonth) ."/".  date('m', $lastMonth) ."/'>&larr;</a>";
    $out .= "<strong>" . strftime('%B %Y', $startTime) . "</strong>"; // i.e. October 2011
    $out .= "<a class='next' href='/ajaxcalendar/". date('Y', $endTime) ."/". date('m', $endTime) ."/'>&rarr;</a>";
    $out .= "</div>";

    // create the calendar header with weekday names
    $out .= "<table class='calendar'><thead><tr>";
    foreach($weekDayNames as $name) $out .= "<th class='dow'>$name</th>";
    $out .= "</tr></thead><tbody><tr>";

    // fill in blank days from last month till we get to first day in this month
    foreach($weekDayNames as $name) {
        if($name == $firstDayName) break;
        $out .= "<td class='emptyday'>&nbsp;</td>";
    }


    // draw the calendar
    for($day = 1; $day <= $daysInMonth; $day++) {

        // get the time info that we need for this day
        $startTime = strtotime("$year-$month-$day 00:00:00");
        $endTime = strtotime("+1 day", $startTime);
        $dayName = strftime('%a', $startTime);

        // if we're at the beginning of a week, start a new row
        if($day > 1 && $dayName == $sun) $out .= "<tr>";

        $currentDay = $eventsPage->children("$field>=$startTime, $field<$endTime,limit=1");

        if($currentDay) {
            $pdfLink = $currentDay[0]->pdf_file ? '<a href="'.$currentDay[0]->pdf_file->httpUrl.'" target="_blank" class="newsLink"><img src="/site/templates/images/calendar/news-icon.gif"></a>' : "";
            $galleryLink = $currentDay[0]->gallery_url ? '<a href="'.$currentDay[0]->gallery_url.'" target="_blank" class="galleryLink"><img src="/site/templates/images/calendar/gallery-icon.gif"></a>' : "";
        }

        // if any events were found for this day, wrap it in <ul> tag
        //if($list) $list = "<ul>$list</ul>";

        // make the day column with day number as header and event list as body
        $out .= "<td class='cell'><div class='date'>$day</h2>";
        if ($currentDay) {
            $out .= "<div class='event'>";
            $out .= $pdfLink.$galleryLink;
            $out .= "</div>";
        }
        $out .= "</td>";

        // if last day in week, then close out the row
        if($dayName == $sat) $out .= "</tr>";
    }

    // finish out the week with blank days for next month
    $key = array_search($dayName, $weekDayNames);
    while(isset($weekDayNames[++$key])) {
        $out .= "<td class='emptyday'>&nbsp;</td>";
    }

    // close the last row and table
    $out .= "</tr></tbody></table>";


    // output the calendar
    return $out;

}


$year = (int) $input->urlSegment1; 
$month = (int) $input->urlSegment2;


// save the last viewed date in a cookie, so the user doens't have to manually scroll to it each time
if (!$year && !$month) {
    // get the year and month from the cookie, if set
    if(isset($_COOKIE['cww_calendar_bookmark'])) {
        $cookieDate = explode("/", $_COOKIE['cww_calendar_bookmark']);
        $month = (int) $cookieDate[1];
        $year = (int) $cookieDate[0];
        //echo ("no segments found but cookie found, cookie is:".$_COOKIE['cww_calendar_bookmark'].", month:".$month." and year:".$year);
    }else{
        // if cookie not set default to current date
        $month = date('n');
        $year = date('Y');
        //echo ("no segments found, no cookie found, month:".$month." and year:".$year);
    }
}else{ // if we do have url segments requesting a specific month store them in the cookie
    setcookie('cww_calendar_bookmark', $year.'/'.$month, time() + (86400 * 30), "/"); // 86400 = 1 day
    //echo ("segments found setting cookie, cookie is now:".$_COOKIE['cww_calendar_bookmark'].", month:".$month." and year:".$year);
}


echo renderCalendar($pages,$year,$month);