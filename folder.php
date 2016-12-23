<?php  
if($page->numChildren) {
	$session->redirect($page->child()->url);
}else{
	echo "This page is a folder, a container which has no content of it's own. Please add some pages inside it in the backend.";
}
?>