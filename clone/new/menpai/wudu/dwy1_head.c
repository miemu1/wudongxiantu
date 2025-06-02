// wusheng_head.c

#include <ansi.h>
#include <armor.h>

inherit HEAD;

string do_wear();

void create()
{
	set_name(HIR "������ñ-����" NOR, ({"dsy1 head"}));
	set_weight(2000);
	if( clonep() )
		set_default_object(__FILE__);
	else {
		set("unit", "��");
		set("long", "а�񼶵�[������ñ-����]\n");
		set("material", "head");    //����
	set("armor_prop/armor", random(50)+120);  //����
	set("armor_prop/warm", 10);   //��ů
		set("value", 10);   //��ֵ
		 set("material", "crimson gold");  //ԭ��
		set("wear_msg", (: do_wear :));  //װ����Ϣ
		set("icon","05081");  //ͼ��
		  set("suit_point",500);
	 //---------------------------------------------------------------
	      //��װ����
		 set("suit",HIR"����-�嶾"NOR);  //��װ����
		set("suit_lvl",5);	     //��װ�ȼ�
		set("suit_count",7);	   //��װ��������
	      //��װ������
		set("suit_mod/arrmor","������װ-����");
		set("suit_mod/finger","����֮��-����");
		set("suit_mod/boots","��������-����");
//		set("suit_mod/hands","����֮��-����");
		set("suit_mod/head","������ñ-����");
		set("suit_mod/neck","����֮��-����");
		set("suit_mod/pants","�����ȼ�-����");
	    //��װȫ�������츳Ч��  //����һ�����ǵڶ������Ե�������������
		set("suit_eff/spirituality",random(1)+7);      //����
		set("suit_eff/constitution",random(1)+4);       // ���
		set("suit_eff/intelligence",random(1)+6);      //����
		set("suit_eff/strength",random(1)+8);      //    һ��
	       //��װȫ�����Ӽ���Ч��
		set("suit_eff_skill/force",10);   //һ��
		set("suit_eff_skill/whip",15);
		set("suit_eff_skill/hand",15);
		set("suit_eff_skill/xiuluo-yinshagong",10);
		set("suit_eff_skill/ruanhong-zhusuo",15);
		set("suit_eff_skill/qianzhu-wandushou",15);

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
			msg = HIC "$N" HIC "���Ὣһ��$n" HIC "����ͷ�ϣ���̬����֮����\n";
		else if (per >= 25)
			msg = HIG "$N" HIG "��$n" HIG "չ��������ͷ�ϡ�\n";
		else if (per >= 20)
			msg = YEL "$N" YEL "��$n" YEL "����ͷ�ϣ����������ӡ�\n";
		else    msg = YEL "$N" YEL "ë��ë�ŵİ�$n" YEL "����ͷ�ϡ�\n";
	} else
	{
		if (per >= 30)
			msg = HIC "$N" HIC "����һ�ӣ���$n" HIC "����ͷ�ϣ���������֮����\n";
		else if (per >= 25)
			msg = HIG "$N" HIG "��$n" HIG "չ��������ͷ�ϡ�\n";
		else if (per >= 20)
			msg = YEL "$N" YEL "��$n" YEL "����ͷ�ϣ����˳��½ǣ����������ӡ�\n";
		else    msg = YEL "$N" YEL "ë��ë�ŵİ�$n" YEL "����ͷ�ϣ����������\n";
	}
	return msg;
}

int query_autoload()
{
	return 1;
}
