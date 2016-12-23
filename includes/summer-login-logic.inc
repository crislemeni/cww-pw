<?php $loginPage = $pages->get("1097");
	$redirectOnLoginPage = $pages->get("1096");
	$sessionLoginVarName = "parentLoggedIn";
	$loginFormUserField = "parent_username";
	$loginFormPassField = "parent_password";
	$loginUserField = "parentUser";
	$loginPassField = "parentPass";

	
		
		$session->login_error = "";

		// If they aren't logged in, then show the login form
		if(!$session->get($sessionLoginVarName)){


			// check for login before redirecting to $loginPage
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

			}else{

				if ($page != $loginPage) {
					$session->redirect($loginPage->path);
				}else{
					$session->login_error = 'Please enter a username and password.';
				}

			}// end IF

		}else if($page == $loginPage){ // if we are already logged in and accessing the login page again, redirect to logged in page.
			$session->redirect($redirectOnLoginPage->path);
		}// end IF ?>