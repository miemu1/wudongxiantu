// new_sowrd.c

#include <weapon.h>
inherit BLADE;

void create()
{
	set_name(HIG "���Ƶ�" NOR, ({ "zb1b"}));
	set_weight(6000);
	if (clonep())
		set_default_object(__FILE__);
	else {
		set("unit", "��");
		set("icon","05035");
		set("long", "����һ�������Ƴɵ�"+this_object()->query("name")+"��������װϵ��!\n");
		set("value", 10000);
		set("material", "steel");
		set("wield_msg", "$N��ৡ���һ�����һ��$n�������С�\n");
		set("unwield_msg", "$N�����е�$n��ص��ʡ�\n");
	  //---------------------------------------------------------------
	      //��װ����
		set("suit",HIG"������װ"NOR);  //��װ����
		set("suit_lvl",1);	     //��װ�ȼ�
		set("suit_count",4);	   //��װ��������
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
	init_blade(175);
	setup();
}
int query_autoload()
{
	return 1;
}