int permit_recruit(object ob)
{
	/*
	if (!wizardp(ob)) {
		command("say �Բ��𣬹������ûͬ��֮ǰ�Ҳ�������ͽ��");
		return 0;
	}*/
	if ((int)ob->query("shen") > 100)
	{
		command("say " + RANK_D->query_respect(ob) +
			"�����������Ҫ���ǳ���а������ʿ���ҿ��㻹�����˰ɡ�");
		return 0;
	}
	
	if( ob->query("detach/�������") ||
	    ob->query("betrayer/�������") )
	{
		command("say �㵱�����������ʲô�ط����������������߾��ߣ���");
		return 0;
	}

	if( ob->query("betrayer/times") )
	{
		command("say �����������Ϊ�����������ܣ�ȴҲ���ղ��Ҳ���֮ͽ��");
		return 0;
	}

	if( ob->query("family/family_name") &&
	    ob->query("family/family_name") != "�������" )
	{
		command("say ���Ѿ���ʦ���ˣ���������������̵���ϸô����");
		return 0;
	}

	return 1;
}
