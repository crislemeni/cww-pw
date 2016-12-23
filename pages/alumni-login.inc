	<div class="innerPageImgHolder">

		<img src="<?= $page->banner_image ? $page->banner_image->getThumb("banner_size") : 
		"http://placehold.it/620x270&text=missing+image" ?>" width="620" height="270" alt="<?= $page->banner_image->description ?>" />
		
		<h3><?= $page->get("headline|title") ?></h3>

	</div>
	<!-- /.innerPageImgHolder -->

	
	<div class="innerPageRTE">
	<?= $page->body; ?>
	
	<div class="parentLoginForm">
	    <div class="loginMessage"><?= $session->login_error ?></div>
	    <div class="loginLogin">
	        <form class="loginLoginForm" action="<?= $page->url ?>" method="post">
	            
	                
	                <label class="loginUsernameLabel"><span>Username:</span>
	                    <input class="loginUsername" type="text" name="parentUser">
	                </label>
	 
	                <label class="loginPasswordLabel"><span>Password:</span>
	                    <input class="loginPassword" type="password" name="parentPass">
	                </label>
	                
	 
	               <!-- -->
	 
	                <input class="loginLoginValue" type="hidden" name="service" value="login">
	                <span class="loginLoginButton"><input type="submit" name="Login" value="Login"></span>
	            
	        </form>
	    </div>
	</div>
	
	</div>