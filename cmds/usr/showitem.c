// unset.c

inherit F_CLEAN_UP;

int help();

int main(object me, string arg)
{
	object ob;
	object obj;
		int value;

	if (! (ob = present(arg, me)))
	{
		write("������û�����ֶ�������\n");
		return 1;
	}

	//if(me->query("combat_exp")<300000)
			//return notify_fail("�����ն񣬵������߽���һ��ʱ������һ����������ҫ��Ķ����ɣ���ȻС�ı��˶��ϣ�\n");

	if (time() - me->query_temp("last_use_channel") < 10)
	{
		return notify_fail("��Ҫ�ڶ�����Ƶ��ʹ��չʾƵ��������Ϣ��\n");
	} else
	{
		me->set_temp("last_use_channel", time());
	}

	if( !arg||!objectp(obj = present(arg,me)) )
			return notify_fail("��Ҫչʾʲô��\n");

		value = ob->query("value");
	//if (value < 2)
		//	return notify_fail("�����Ʒ��ֵǮ��չʾʲô��\n");

	message("channel:bill", "��չʾ��"+me->query("name")+"����Ʒչʾ->"+ZJURL("cmds:look "+arg)+ZJSIZE(22)+filter_color(obj->query("name"))+NOR"��\n", users());
	return 1;
}

int help()
{
	write(@TEXT
ָ���ʽ��showitem <��Ʒ>
��Ʒչʾ�Ͳ鿴��

TEXT
	);
	return 1;
}
