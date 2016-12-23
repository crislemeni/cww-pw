<?php 
	function customLogin($loginPage,$redirectOnLoginPage,$sessionLoginVarName,$loginFormUserField,$loginFormPassField,$loginUserField,$loginPassField) {

		if ($page == $loginPage || $loginPage->children->has($page) ) {
			
			$session->login_error = "";

			// If they aren't logged in redirect them to $loginPage
			if(!$session->get($sessionLoginVarName)){


				// but first check for login info before redirecting to $loginPage
				if($input->post->parentUser && $input->post->parentPass) {

					$correctUser = $sanitizer->text($input->post->$loginUserField);
					$correctPass = $sanitizer->text($input->post->$loginPassField);

					if($correctUser == $loginPage->$loginFormUserField && $correctPass == $loginPage->$loginFormPassField) {
						// login successful
						$session->$sessionLoginVarName = 1;
						$session->redirect($redirectOnLoginPage->path);
					}  else {
						$session->login_error = 'Login Failed. Please try again.';
					}// end IF

				}else{ // if they are logged in take them to the logged in page

					if ($page != $loginPage) {
						$session->redirect($loginPage->path);
					}

				}// end IF

			}// end IF
		} // enf IF
		
	} // EOF
 ?>