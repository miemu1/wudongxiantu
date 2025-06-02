#pragma save_binary
#include <ansi.h>
#include <armor.h>
inherit BOOTS;

string do_wear();
void create()
{
	set_name(HIR"��ʥѥ��"NOR, ({"wusheng boots"}));
	set_weight(300);
	if( clonep() )
		set_default_object(__FILE__);
	else {
		set("unit", "˫");
		set("long", "���߼���[��ʥ]ѥ��\n");
		set("material", "boots");    //����
	set("armor_prop/armor", random(40)+20);  //����
	set("armor_prop/warm", 3);   //��ů
		set("value", 1000);   //��ֵ
		set("material", "crimson gold");  //ԭ��
		set("wear_msg", (: do_wear :));  //װ����Ϣ
//---------------------------------------------------------------
	      //��װ����
		 set("suit",HIR"��ʥ"NOR);  //��װ����
		set("suit_lvl",5);	     //��װ�ȼ�
		set("suit_count",7);	   //��װ��������
	      //��װ������
		set("suit_mod/arrmor","��ʥ����");
		set("suit_mod/finger","��ʥ��ָ");
		set("suit_mod/boots","��ʥѥ��");
//		set("suit_mod/hands","��ʥ����");
		set("suit_mod/head","��ʥ����");
		set("suit_mod/neck","��ʥ����");
		set("suit_mod/pants","��ʥ����");			
     
	    //��װȫ�������츳Ч��  //����һ�����ǵڶ������Ե�������������
		set("suit_eff/constitution",random(2)+2);       //����
		set("suit_eff/spirituality",random(2)+2);      // ��� 
		set("suit_eff/intelligence",random(2)+2);      //����  
		set("suit_eff/strength",random(2)+2);      //    һ��  
	       //��װȫ�����Ӽ���Ч��   
		set("suit_eff_skill/strike",5);   //һ��
		set("suit_eff_skill/cuff",5);
		set("suit_eff_skill/claw",5);
		set("suit_eff_skill/hand",5);
		set("suit_eff_skill/finger",5);
	   
       
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
			msg = HIC "$N" HIC "���Ὣһ��$n" HIC "���ڽ��ϣ���̬����֮����\n";
		else if (per >= 25)
			msg = HIG "$N" HIG "��$n" HIG "չ�������ڽ��ϡ�\n";
		else if (per >= 20)
			msg = YEL "$N" YEL "��$n" YEL "���ڽ��ϣ����������ӡ�\n";
		else    msg = YEL "$N" YEL "ë��ë�ŵİ�$n" YEL "���ڽ��ϡ�\n";
	} else
	{
		if (per >= 30)
			msg = HIC "$N" HIC "����һ�ӣ���$n" HIC "���ڽ��ϣ���������֮����\n";
		else if (per >= 25)
			msg = HIG "$N" HIG "��$n" HIG "չ�������ڽ��ϡ�\n";
		else if (per >= 20)
			msg = YEL "$N" YEL "��$n" YEL "���ڽ��ϣ����˳��½ǣ����������ӡ�\n";
		else    msg = YEL "$N" YEL "ë��ë�ŵİ�$n" YEL "���ڽ��ϣ����������\n";
	}
	return msg;
}

int query_autoload()
{
	return 1;
}