inherit NPC;
#include <localtime.h>

void create()
{
	set_name("������ҽ", ({"shenyi"}));
	set("long", "������һ������Ķ����㣡");
	set("combat_exp", 10000);
	
	setup();
}

void init()
{
	add_action("do_zhengrong", "zhengrong");
}

int do_zhengrong(string arg)
{
	object who = this_player();
	int last_time, num;
	
	
	last_time = who->query("fuben_moku/last_time");
	if ((localtime(last_time)[LT_MON] == localtime(time())[LT_MON]) && (localtime(last_time)[LT_MDAY] == localtime(time())[LT_MDAY]))
	{
		write(ZJOBLONG + "һ��ֻ������һ�Ρ�\n");
		return 0;
	}
	
	if (!arg)
	{
		write(INPUTTXT("һ��һ�Σ�����1��50��������Ϊ���շѡ�"ZJBR"���뽫��ò�޸�Ϊ���٣�(10-30)", "zhengrong $txt#") + "\n");
		return 0;
	}
	
	if (!sscanf(arg, "%d", num) || num < 10 || num > 30)
	{
		write(ZJOBLONG + "������һ������10��С��30������\n");
		return 0;
	}
	
	if (!MONEY_D->player_pay(who, 10000) && who->query("combat_exp") > 500000)
		return notify_fail(ZJOBLONG + "���Ǯ������\n");
	
	who->set("per", num);
	write("���ݳɹ��������ò�޸�Ϊ" + num + "��\n");
	return 1;
}