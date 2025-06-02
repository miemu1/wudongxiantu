//tianxing.c
#include <ansi.h>

inherit COMBINED_ITEM;

void do_character(object player, string character);

void create()
{
	set_name(HIR"���Ե�[��]" NOR, ({ "tianxing dan"}) );
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
        set("no_give",1);
        set("no_drop",1);
        set("no_get",1);
        set("no_steal",1);
//		set("no_shop", 1);//�¼�
		set("long","һ�ź��ĵ�ҩ����˵"+ZJURL("cmds:fuyong tianxing dan")+ZJSIZE(22)+HIG
				+"����"NOR"��ɸı��Լ������ԡ�"ZJBR+HIR"ע�⣺ֻ��ʹ��һ�Σ��Ҳ��������Եļ��ܻᱻ��������ã�"NOR"\n");
		set("yuanbao", 1200);
	}
	set("action_list", ([
		"ʹ��" : "fuyong tianxing dan",
	]));
	set_amount(1);
	setup();
	
}

void init()
{
	add_action("do_eat", "fuyong");
}

int do_eat(string arg)
{
	object me = this_player();		
	object ob;		
	string character, id, id2, msg;
	
	if (me->query("fuyongtianxing", 1)) {
		tell_object(me, "���Ѿ�ʹ�ù�һ�����Ե��ˣ���������ʹ�á�\n");
		return 1;
	}
	if (sscanf(arg,"%s %s %s", character, id, id2) != 3)
	{
		msg = ZJOBLONG +HIR"ע�⣺ֻ��ʹ��һ�Σ��Ҳ��������Եļ��ܻᱻ��������ã�"NOR+ZJBR+
		      "�ĺ���������ʦ����-�������"ZJBR
			"�������䣬��ʦ����-�׻����"ZJBR
			"�����䣬��ʦ����-�������"ZJBR
			"���ռ�թ����ʦ����-��ȸ���"ZJBR
			HIY"��ǰ���ԣ�"+me->query("character")+ZJBR+NOR+HIG"��ѡ������Ҫ�����ԣ�"NOR"\n";
		
		msg += ZJOBACTS2+ZJMENUF(2,2,9,30);
		msg += "��������:fuyong �������� tianxing dan";
		msg += ZJSEP"������:fuyong ������ tianxing dan";
		msg += ZJSEP"���ռ�թ:fuyong ���ռ�թ tianxing dan";
		msg += ZJSEP"�ĺ�����:fuyong �ĺ����� tianxing dan";
		
		write(msg + "\n");
		return 1;
	}
	if (!id(id + " " +id2))
		return 0;	
	
	if( !objectp(ob = present(id + " " +id2, me)) )
		return 0;	
		
	tell_object(me, "��һ����������һ��" + name() +"��\n");
	
	do_character(me, character);

	return 1;
}

void do_character(object player, string character)
{
	if (character !="��������" && character !="������" && character !="���ռ�թ" && character !="�ĺ�����") {
		tell_object(player, "û���������ԣ�\n");
		return;
	}

	if(player->query("character") == character)
	{
		tell_object(player,sprintf("�㱾������%s��\n", character));
		return;
	}

	player->set("character", character);
	tell_object(player,"�ı�����Ϊ��"+character+"���ɹ���\n");
	//�����������ļ����Ƿ����Ҫ�󣬲����ϵ�ɾ��
	UPDATE_D->check_skill(player);
	player->set("fuyongtianxing", time());
	player->save();
	log_file("/cmds/tianxing", sprintf("%s %s %s\n", player->name()+"("+player->query("id")+")", "����="+character, CHINESE_D->chinese_date(time(), 2)));
	add_amount(-1);
}
