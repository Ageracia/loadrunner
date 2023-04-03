Action()
{
	int i = 1;
	int x = atoi(lr_eval_string("{X}"));

	lr_start_transaction("MAIN_PAGE");

	web_reg_save_param_regexp(
		"ParamName=act_token",
		"RegExp=act=(.*?);",
		LAST);

	web_reg_save_param_regexp(
		"ParamName=dwhsplit",
		"RegExp=\"split\":\"(.*?)\",",
		LAST);
	
	web_reg_save_param_regexp(
		"ParamName=token",
		"RegExp=\"token\":\"(.*?)\"",
		LAST);
	
	web_url("login_2", 
		"URL=https://account.mail.ru/login", 
		"TargetFrame=", 
		"Resource=0", 
		"RecContentType=text/html", 
		"Referer=", 
		"Snapshot=t444.inf", 
		"Mode=HTML", 
		LAST);

	lr_end_transaction("MAIN_PAGE",LR_AUTO);

	lr_start_transaction("LOG_IN");

	web_submit_data("info", 
		"Action=https://auth.mail.ru/api/v1/pushauth/info", 
		"Method=POST", 
		"EncType=multipart/form-data", 
		"TargetFrame=", 
		"RecContentType=application/json", 
		"Referer=https://account.mail.ru/", 
		"Snapshot=t540.inf", 
		"Mode=HTML", 
		ITEMDATA, 
		"Name=login", "Value={login}", ENDITEM, 
		"Name=htmlencoded", "Value=false", ENDITEM, 
		"Name=email", "Value={login}", ENDITEM, 
		LAST);
	
	
	// При успешной авторизации в headers ответа будет параметр back равный 1.
	// Если авторизация не прошла, в headers ответа будет параметр fail=1.
	web_reg_find(
		"Search=Headers",
		"Text=back\=1",

		LAST);

	web_submit_data("auth",
		"Action=https://auth.mail.ru/cgi-bin/auth",
		"Method=POST",
		"EncodeAtSign=YES",
		"TargetFrame=",
		"RecContentType=text/html",
		"Referer=https://account.mail.ru/",
		"Snapshot=t542.inf",
		"Mode=HTML",
		ITEMDATA,
		"Name=username", "Value={login}", ENDITEM,
		"Name=Login", "Value={login}", ENDITEM,
		"Name=password", "Value={pwd}", ENDITEM,
		"Name=Password", "Value={pwd}", ENDITEM,
		"Name=new_auth_form", "Value=1", ENDITEM,
		"Name=FromAccount", "Value=opener=account&twoSteps=1", ENDITEM,
		"Name=act_token", "Value={act_token}", ENDITEM,
		"Name=page", "Value=https://e.mail.ru/messages/inbox?authid=lfr6w3c2.7j&back=1&dwhsplit={dwhsplit}&from=login&x-login-auth=1", ENDITEM,
		"Name=back", "Value=1", ENDITEM,
		"Name=lang", "Value=ru_RU", ENDITEM,
		LAST);

	lr_end_transaction("LOG_IN",LR_AUTO);
	
	
	for(; i <= x; i++)
	    {
	
			lr_start_transaction("SEND_MESSAGE");
			
			web_reg_save_param_json(
				"ParamName=token_1",
				"QueryString=$.body.token",
				LAST);
		
			web_submit_data("short",
				"Action=https://e.mail.ru/api/v1/user/short",
				"Method=POST",
				"EncodeAtSign=YES",
				"TargetFrame=",
				"RecContentType=application/json",
				"Referer=https://e.mail.ru/inbox/?authid=lfr6w3c2.7j&back=1%2C1&dwhsplit={dwhsplit}&from=login&x-login-auth=1&afterReload=1",
				"Snapshot=t553.inf",
				"Mode=HTML",
				ITEMDATA,
				"Name=email", "Value={login}", ENDITEM,
				"Name=htmlencoded", "Value=false", ENDITEM,
				"Name=token", "Value={token}", ENDITEM,
				LAST);	
			
			//При отправке на любой адрес в случае успеха в теле ответа будет параметр "status"="200"
			
			web_reg_find(
				"Text=status\":200",
				LAST);
			
			web_submit_data("send",
				"Action=https://e.mail.ru/api/v1/messages/send",
				"Method=POST",
				"EncodeAtSign=YES",
				"TargetFrame=",
				"RecContentType=application/json",
				"Referer=https://e.mail.ru/inbox/?authid=lfr6w3c2.7j&back=1%2C1&dwhsplit={dwhsplit}&from=login&x-login-auth=1&afterReload=1",
				"Snapshot=t556.inf",
				"Mode=HTML",
				ITEMDATA,
				"Name=ATTACHMENTS_RESTORE", "Value=true", ENDITEM,
				"Name=ATTACHMENTS_EXPIRATION_TIME", "Value=14400000", ENDITEM,
				"Name=id", "Value=fD0fBaA0D5cB7E3c4c7059eEe2Da94Cc", ENDITEM,
				"Name=source", "Value={\"draft\":\"\",\"reply\":\"\",\"forward\":\"\",\"schedule\":\"\"}", ENDITEM,
				"Name=headers", "Value={}", ENDITEM,
				"Name=template", "Value=0", ENDITEM,
				"Name=sign", "Value=0", ENDITEM,
				"Name=remind", "Value=0", ENDITEM,
				"Name=receipt", "Value=false", ENDITEM,
				"Name=subject", "Value=", ENDITEM,
				"Name=priority", "Value=3", ENDITEM,
				"Name=send_date", "Value=", ENDITEM,
				"Name=body", "Value={\"html\":\"<div>{time}</div><div>&nbsp;</div><div data-signature-widget=><div data-signature-widget=><div>--<br>oleg oleg<br>РћС‚РїСЂР°РІР»РµРЅРѕ РёР· РџРѕС‡С‚С‹ <a href=\\\"https://trk.mail.ru/c/zzm979\\\">Mail.ru</a></div></div></div>\",\"text\":\"{time}\"}", ENDITEM,
				"Name=from", "Value=<{login}>", ENDITEM,
				"Name=correspondents", "Value={\"to\":\"{whom}\",\"cc\":\"\",\"bcc\":\"\"}", ENDITEM,
				"Name=folder_id", "Value=", ENDITEM,
				"Name=triggerModelChangePlease", "Value=true", ENDITEM,
				"Name=compose_stat", "Value={\"user_track\":\"m|1553|208|1|1;m|416|247|1|1;m|374|26|1|0;k|4761|6;c|7983|0|439|231;m|73|110|1|1;k|5864|6;m|3131|35|1|1;m|202|47|1|1;m|201|104|1|1;m|202|53|1|0;m|202|89|1|1;m|201|41|1|0;m|200|18|1|0;m|203|3|1|0;m|201|4|1|1;c|1736|0|334|584\",\"build\":\"release-fmail-19981.1970-01-02T14_49_57\",\"serverTime\":1679500563256}", ENDITEM,
				"Name=delay_for_cancellation", "Value=true", ENDITEM,
				"Name=attaches", "Value={\"list\":[]}", ENDITEM,
				"Name=email", "Value={login}", ENDITEM,
				"Name=htmlencoded", "Value=false", ENDITEM,
				"Name=token", "Value={token_1}", ENDITEM,
				LAST);
		
			lr_end_transaction("SEND_MESSAGE",LR_AUTO);	 
	    }

	lr_start_transaction("LOG_OUT");
	
	web_reg_find(
		"Text=Mail.ru",
		LAST);
	
	web_url("logout", 
		"URL=https://auth.mail.ru/cgi-bin/logout?next=1&lang=ru_RU&page=https%3A%2F%2Fmail.ru%2F%3Ffrom%3Dlogout", 
		"TargetFrame=", 
		"Resource=0", 
		"RecContentType=text/html", 
		"Referer=https://e.mail.ru/", 
		"Snapshot=t559.inf", 
		"Mode=HTML",       
		LAST);

	lr_end_transaction("LOG_OUT",LR_AUTO);

	return 0;
}