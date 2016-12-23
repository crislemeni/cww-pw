<div class="parentLoginForm">
	<?php if ($alumniFormError != ""): ?>
		<p><?= $alumniFormError ?></p>
	<?php endif ?>

	<div class="loginLogin">
		
		<form class="loginLoginForm" action="<?= $page->url ?>" method="post">
            
                
                <label class="loginUsernameLabel"><span>Username:</span>
                    <input class="loginUsername" type="text" name="alumni_username">
                </label>
 
                <label class="loginPasswordLabel"><span>Password:</span>
                    <input class="loginPassword" type="password" name="alumni_password">
                </label>
 
                <span class="loginLoginButton"><input type="submit" name="Login" value="Login"></span>
            
        </form>

		
	</div>
	<!-- /.loginLogin -->
</div>
<!-- /.parentLoginForm -->