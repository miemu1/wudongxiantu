// qizong.h

int permit_recruit(object ob)
{
	

	if (ob->query("detach/佻�����") ||
	    ob->query("betrayer/佻�����"))
	{
		command("say 佻������Խ�δ���չ����ŵ��ӣ�");
		return 0;
	}

	if (ob->query("betrayer/times"))
	{
		command("say 佻����ɽ����ľ������壬������ʦ֮��������⣿");
		return 0;
	}

	if (ob->query("family/family_name") &&
	    ob->query("family/family_name") != "佻�����")
	{
		command("say ���������ʦָ�㣬���α�������佻����ɣ�");
		return 0;
	}

	return 1;
}
