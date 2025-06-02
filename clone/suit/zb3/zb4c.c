// news_pants.c

#include <ansi.h>
#include <armor.h>

inherit HANDS;

string do_wear();

void create()
{
	set_name(HIG "��������" NOR, ({"zb4b"}));   //�ٱ�ʾΪ1����װ
	set_weight(3000);
	if( clonep() )
		set_default_object(__FILE__);
	else {
		set("unit", "��");
		set("long", "����һ��"+this_object()->query("name")+"��������װϵ�С�\n");
		set("material", "hands");    //����
	set("armor_prop/armor", 20);  //����
	set("armor_prop/warm", 5);   //��ů
		set("value", 1000);   //��ֵ	 
		set("wear_msg", (: do_wear :));  //װ��ʱ��ʾ����Ϣ
      //---------------------------------------------------------------
	      //��װ����
		set("suit",HIG"������װ"NOR);  //��װ����
		set("suit_lvl",1);	     //��װ�ȼ�
		set("suit_count",6);	   //��װ��������
	       //��װ������
		set("suit_mod/cloth","���Ƴ���");
		set("suit_mod/boots","���ƿ�ѥ");
		set("suit_mod/pants","���Ƴ���");
		set("suit_mod/sword","���ƽ�");
		set("suit_mod/blade","���Ƶ�");
//		set("suit_mod/hands","��������");
	       //��װȫ�������츳Ч��  
		set("suit_eff/strength",1);      //����
		set("suit_eff/intelligence",1);      //����  
		set("suit_eff/spirituality",1);      //    һ��
		set("suit_eff/constitution",1);      //����  
		//��װȫ�����Ӽ���Ч��     
	       set("suit_eff_skill/dodge",50);   
	       set("suit_eff_skill/sword",50);
	       set("suit_eff_skill/blade",50);
	       set("suit_eff_skill/cuff",50);
	       set("suit_eff_skill/strike",50);
	       set("suit_eff_skill/finger",50);
	       set("suit_eff_skill/claw",50);
       //------------------------------------------------------
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
