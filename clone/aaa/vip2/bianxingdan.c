//bianxingdan.c
#include <ansi.h>

inherit COMBINED_ITEM;

void do_gender(object player, string gender);

void create()
{
	set_name(HIR"���Ե�[��]" NOR, ({ "bianxing dan"}) );
	set_weight(1);
	if( clonep() )
		set_default_object(__FILE__);
	else
	{
		set("base_unit", "��");
		set("unit", "��");
		set("base_value", 1);
		set("base_weight", 1);
		set("value", 1);
		set("channel_id","ϵͳ");
		set("no_sell",1);
		set("no_steal",1);
        set("no_shop", 1);// �¼�
		set("long","һ�ź��ĵ�ҩ����˵"+ZJURL("cmds:fu bianxing dan")+ZJSIZE(22)+HIG
				+"����"NOR"��ɸı��Լ����Ա�"ZJBR+HIR"ע�⣺ֻ��ʹ��һ�Σ��Ҳ��������Եļ��ܻᱻ��������ã�"NOR"\n");
		set("yuanbao", 1500);
	}
	set("action_list", ([
		"ʹ��" : "fu bianxing dan",
	]));
	set_amount(1);
	setup();
	
}

void init()
{
	add_action("do_eat", "fu");
}

int do_eat(string arg)
{
	object me = this_player();		
	object ob;		
	string gender, id, id2, msg;
	
	if (me->query("fubianxingdan", 1)) {
		tell_object(me, "���Ѿ�ʹ�ù�һ�α��Ե��ˣ���������ʹ�á�\n");
		return 1;
	}
	if (sscanf(arg,"%s %s %s", gender, id, id2) != 3)
	{
		msg = ZJOBLONG +HIR"ע�⣺ֻ��ʹ��һ�Σ��Ҳ��������Եļ��ܻᱻ��������ã�"NOR+ZJBR+
			HIY"��ǰ�Ա�"+me->query("gender")+ZJBR+HIG"��ѡ������Ա�"NOR"\n";
		
		msg += ZJOBACTS2+ZJMENUF(2,2,9,30);
		msg += "����:fu ���� bianxing dan";
		msg += ZJSEP"Ů��:fu Ů�� bianxing dan";
		msg += ZJSEP"������:fu ���� bianxing dan";
		
		write(msg + "\n");
		return 1;
	}
	if (!id(id + " " +id2))
		return 0;	
	
	if( !objectp(ob = present(id + " " +id2, me)) )
		return 0;	
		
	tell_object(me, "��һ����������һ��" + name() +"��\n");
	
	do_gender(me, gender);

	return 1;
}

void do_gender(object player, string gender)
{
	if (gender !="����" && gender !="Ů��" && gender !="����") {
		tell_object(player, "û�������Ա�\n");
		return;
	}

	if(player->query("gender") == gender)
	{
		tell_object(player,sprintf("�㱾������%s��\n", gender));
		return;
	}

	player->set("gender", gender);
	tell_object(player,"����Ϊ��"+gender+"���ɹ���\n");
	//�����������ļ����Ƿ����Ҫ�󣬲����ϵ�ɾ��
	UPDATE_D->check_skill(player);
	player->set("fubianxingdan", time());
	player->save();
	log_file("/cmds/bianxingdan", sprintf("%s %s %s\n", player->name()+"("+player->query("id")+")", "����="+gender, CHINESE_D->chinese_date(time(), 2)));
	add_amount(-1);
}
