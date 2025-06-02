// zhenwu_hands.c

#include <ansi.h>
#include <armor.h>

inherit HANDS;

string do_wear();

void create()
{
	set_name(HIR "�氮����" NOR, ({"zhenai hands"}));
	set_weight(3000);
	if( clonep() )
		set_default_object(__FILE__);
	else {
		set("unit", "ֻ");
		set("long", "����������[�氮]������\n");
		set("material", "hands");    //����
		set("armor_prop/armor", 9999999);  //����
		set("armor_prop/warm", 1);   //��ů
	       set("value", 10000000);   //��ֵ
		set("material", "crimson gold");  //ԭ��
		set("wear_msg", (: do_wear :));  //װ����Ϣ
		set("icon","05084");
		  set("suit_point",500);
	//---------------------------------------------------------------
//��װ����
		 set("suit",HIR"��ǰ��"NOR);  //��װ����
		set("suit_lvl",5);	     //��װ�ȼ�
		set("suit_count",6);	   //��װ��������
	      //��װ������
		set("suit_mod/arrmor","����");
		set("suit_mod/finger","�氮ħ��");
		set("suit_mod/sword","���ǽ�");
		set("suit_mod/hands","�氮����");
		set("suit_mod/head","ͷ��");
		set("suit_mod/neck","���ٻ���");
		set("suit_mod/pants","���Ѽ�");			     
	  //��װȫ�������츳Ч��  //����һ�����ǵڶ������Ե�������������
		set("suit_eff/spirituality",22222);      //����
		set("suit_eff/constitution",22222);      // ��� 
		set("suit_eff/intelligence",22222);      //����  
		set("suit_eff/strength",22222);      //    һ��  
		//set("suit_eff/qi",22222);   
	       //��װȫ�����Ӽ���Ч��   
		/*set("suit_eff_skill/liangyi-yinyangjue",9999999);   //һ��
		set("suit_eff_skill/buxiujianshu",9999999); 
		set("suit_eff_skill/dodge",9999999); 
		set("suit_eff_skill/force",9999999); 
		set("suit_eff_skill/parry",9999999); 
		set("suit_eff_skill/sword",9999999); 
		set("suit_eff_skill/lunhui-sword",9999999); 
		set("suit_eff_skill/lingbo-weibu",9999999); 
		set("suit_eff_skill/qiankun-danuoyi",9999999); 
		set("suit_eff_skill/sword-cognize",9999999); 
		set("suit_eff_skill/martial-cognize",9999999); 
		set("suit_eff_skill/unarmed",9999999); 
		set("suit_eff_skill/buddhism",9999999);
		set("suit_eff_skill/lamaism",9999999);  
		set("suit_eff_skill/taoism",9999999);	*/   
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
