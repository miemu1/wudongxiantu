#include <ansi.h>

inherit F_CLEAN_UP;

int main(object me, string arg)
{
	string str,nb,*text,short_name,*dk, name;
	int i, index;
	object *inv,store;
/*
	if (!wizardp(me))
	{
		write("��ʱ��մ�������ܡ������ṩBUGԭ�򡣹�����Զ��δ�������⡣\n");
		return 1;
	} */
	if(!objectp(store=present("chuwu dai",me)))
	{
		store = new("/clone/misc/baibao");
		store->move(me);
	}
	if (store->query("owner_id") != me->query("id"))
		store->set("owner_id", me->query("id"));
	if (!arg)
	{
		str = ZJOBLONG+sprintf("��ѡ��鿴�����ͣ�"+"\n");
		str += ZJOBACTS2+ZJMENUF(3,3,9,30);
		str += "������Ʒ:mystore ȫ�� 1";
		str += ZJSEP+ "������:mystore ���� 1";
		str += ZJSEP+"������:mystore ���� 1";
		str += ZJSEP+"������:mystore �ӻ� 1";
		str += ZJSEP+"��  ��:mystore ����";
		
		write(str+"\n");
		return 1;
	}
	if (arg == "����")
	{
		write(INPUTTXT("�����������Ĺؼ���","mystore ���� $txt# 1")+"\n");
		return 1;
	} else
	if (arg == "ȫ�� 1"  || arg == "���� 1" || arg == "���� 1" || arg == "�ӻ� 1")
	{
		store->query_item(arg);
		return 1;
	} else	
	if (arg=="put")
	{
		inv = all_inventory(me);
		if (! sizeof(inv))
		{
			write(ZJOBLONG+HIY"Ŀǰ������û���κζ�����""\n");
			return 1;
		}
		dk = ({});
		for (i = 0; i < sizeof(inv); i++)
		{
			if (inv[i]->query("equipped") ||inv[i]->query("no_put")||inv[i]->query("money_id") || inv[i]->query("id") == "chuwu dai") continue;

			short_name = inv[i]->query("name");
			if(inv[i]->query_amount())
				short_name = inv[i]->query_amount() + inv[i]->query("base_unit") + short_name;

			dk += ({ short_name + ":mystore put " + file_name(inv[i]) });
		}
		text = sort_array(dk, 1);

		str = ZJOBLONG"�������ֿ��д�ʲô������"+"\n";
		str += ZJOBACTS2+ZJMENUF(3,3,9,30);
		if (! sizeof(text))
		{
			write(ZJOBLONG+HIY"Ŀǰ������û��Ҫ����ֿ�Ķ�����"NOR+"\n");
			return 1;
		}
		str += implode(text, ZJSEP);
		write(str+"\n");
		return 1;
	} else if (sscanf(arg,"���� %s %d", name, index) == 2)
	{
		store->query_item(arg);
		return 1;
	} else	if (sscanf(arg,"get %s %d", nb, index)==2)
	{
		store->get_item(nb, index);
		return 1;
	} else	if (sscanf(arg,"put %s %d", nb, index)==2)
	{
		store->do_store(nb, index);
		return 1;
	} else if (sscanf(arg,"ȫ�� %d", index) == 1)
	{
		store->query_item(arg);
		return 1;
	} else if (sscanf(arg,"���� %d", index) == 1)
	{
		store->query_item(arg);
		return 1;
	} else if (sscanf(arg,"���� %d", index) == 1)
	{
		store->query_item(arg);
		return 1;
	} else if (sscanf(arg,"�ӻ� %d", index) == 1)
	{
		store->query_item(arg);
		return 1;
	} else if (sscanf(arg,"get %s",nb)==1)
	{
		store->get_item(nb);
		return 1;
	} else if (sscanf(arg,"put %s",nb)==1)
	{
		store->do_store(nb);
		return 1;
	}
	else
		return notify_fail(HIM"�����ʲô����"NOR"\n");

	return 1;
}

int help(object me)
{
     write(@HELP

�ֿ������

HELP
    );
    return 1;
}
