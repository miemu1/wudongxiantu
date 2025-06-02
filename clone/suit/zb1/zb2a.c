// news_cloth.c

#include <ansi.h>
#include <armor.h>

inherit BOOTS;

string do_wear();

void create()
{
	set_name(HIG "���Ϳ�ѥ" NOR, ({"zb2a"}));
	set_weight(300);
	if( clonep() )
		set_default_object(__FILE__);
	else {
		set("unit", "˫");
		set("long", "����һ��"+this_object()->query("name")+"���ǵ��������ر�Ϊ���˶����ġ�\n");
		set("material", "boots");    //����
	set("armor_prop/dodge", 25);  //����
	set("armor_prop/warm", 5);   //��ů
		set("value", 100000);   //��ֵ
		set("wear_msg", (: do_wear :));  //װ����Ϣ
      //---------------------------------------------------------------
	      //��װ����
		set("suit",HIG"������װ"NOR);  //��װ����
		set("suit_lvl",1);	     //��װ�ȼ�
		set("suit_count",4);	   //��װ��������
	      //��װ������
		set("suit_mod/cloth","���ͳ���");
		set("suit_mod/boots","���Ϳ�ѥ");
		set("suit_mod/pants","���ͳ���");
		set("suit_mod/sword","���ͽ�");
		set("suit_mod/blade","���͵�");
//		set("suit_mod/hands","��������");
	       //��װȫ�������츳Ч��  
		set("suit_eff/strength",1);      //����
		set("suit_eff/intelligence",1);      //����  
		set("suit_eff/spirituality",1);      //    һ��
		set("suit_eff/constitution",1);      //����  
		//��װȫ�����Ӽ���Ч��     
	       set("suit_eff_skill/dodge",25);   
	       set("suit_eff_skill/sword",25);
	       set("suit_eff_skill/blade",25);
	       set("suit_eff_skill/cuff",25);
	       set("suit_eff_skill/strike",25);
	       set("suit_eff_skill/finger",25);
	       set("suit_eff_skill/claw",25);
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
