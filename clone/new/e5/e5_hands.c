// lingdong_hands.c

#include <ansi.h>
#include <armor.h>

inherit WRISTS;

string do_wear();

void create()
{
	set_name(HIG "�鶯����" NOR, ({"lingdong hands"}));
	set_weight(3000);
	if( clonep() )
		set_default_object(__FILE__);
	else {
		set("unit", "˫");
		set("long", "���߼���[�鶯]����\n");
		set("material", "neck");    //����
	set("armor_prop/armor", random(40)+20);  //����
	set("armor_prop/warm", 1);   //��ů
	       set("value", 1000);   //��ֵ
		set("material", "crimson gold");  //ԭ��
		set("wear_msg", (: do_wear :));  //װ����Ϣ
		set("icon","05084");
		  set("suit_point",500);
	//---------------------------------------------------------------
	      //��װ����
		 set("suit",HIG"�鶯"NOR);  //��װ����
		set("suit_lvl",5);	     //��װ�ȼ�
		set("suit_count",7);	   //��װ��������
	      //��װ������
		set("suit_mod/arrmor","�鶯����");
		set("suit_mod/finger","�鶯ָ��");
		set("suit_mod/whip","�鶯����");
//		set("suit_mod/hands","�鶯����");
		set("suit_mod/head","�鶯����");
		set("suit_mod/neck","�鶯����");
		set("suit_mod/pants","�鶯�ȼ�");
	    //��װȫ�������츳Ч��  //����һ�����ǵڶ������Ե�������������
		set("suit_eff/constitution",random(2)+2);       //����
		set("suit_eff/spirituality",random(2)+2);      // ���
		set("suit_eff/intelligence",random(2)+2);      //����
		set("suit_eff/strength",random(2)+2);      //    һ��
	       //��װȫ�����Ӽ���Ч��
		set("suit_eff_skill/whip",10);   //һ��
		set("suit_eff_skill/dodge",10);

       //---------------------------------------------------------------
	}
	setup();
}

string do_wear()
{
	object me;
	string msg;
	int per;

	me = this_player();
	per = me->query("per");
	if (me->query("gender") == "Ů��")
	{
		if (per >= 30)
			msg = HIC "$N" HIC "���Ὣһ��$n" HIC "�������ϣ���̬����֮����\n";
		else if (per >= 25)
			msg = HIG "$N" HIG "��$n" HIG "չ�����������ϡ�\n";
		else if (per >= 20)
			msg = YEL "$N" YEL "��$n" YEL "�������ϣ����������ӡ�\n";
		else    msg = YEL "$N" YEL "ë��ë�ŵİ�$n" YEL "�������ϡ�\n";
	} else
	{
		if (per >= 30)
			msg = HIC "$N" HIC "����һ�ӣ���$n" HIC "�������ϣ���������֮����\n";
		else if (per >= 25)
			msg = HIG "$N" HIG "��$n" HIG "չ�����������ϡ�\n";
		else if (per >= 20)
			msg = YEL "$N" YEL "��$n" YEL "�������ϣ����˳��½ǣ����������ӡ�\n";
		else    msg = YEL "$N" YEL "ë��ë�ŵİ�$n" YEL "�������ϣ����������\n";
	}
	return msg;
}

int query_autoload()
{
	return 1;
}
