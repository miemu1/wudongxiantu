// new_sowrd.c

#include <weapon.h>
inherit SWORD;

void create()
{
	set_name(HIG "��Ӱ��" NOR, ({ "zb6b"}));
	set_weight(6000);
	if (clonep())
		set_default_object(__FILE__);
	else {
		set("unit", "��");
		set("icon","05035");
		set("long", "����һ�������Ƴɵ�"+this_object()->query("name")+"����Ӱ��װϵ��!\n");
		set("value", 1000);
		set("material", "steel");
		set("wield_msg", "$N��ৡ���һ�����һ��$n�������С�\n");
		set("unwield_msg", "$N�����е�$n��ؽ��ʡ�\n");
	  //---------------------------------------------------------------
	      //��װ����
		set("suit",HIG"��Ӱ��װ"NOR);  //��װ����
		set("suit_lvl",1);	     //��װ�ȼ�
		set("suit_count",4);	   //��װ��������
	      //��װ������
		set("suit_mod/cloth","��Ӱ����");
		set("suit_mod/boots","��Ӱ��ѥ");
		set("suit_mod/pants","��Ӱ����");
		set("suit_mod/sword","��Ӱ��");
		set("suit_mod/blade","��Ӱ��");
//		set("suit_mod/hands","��Ӱ����");
	       //��װȫ�������츳Ч��  
		set("suit_eff/strength",1);      //����
		set("suit_eff/intelligence",1);      //����  
		set("suit_eff/spirituality",1);      //    һ��
		set("suit_eff/constitution",1);      //����  
		//��װȫ�����Ӽ���Ч��     
	       set("suit_eff_skill/dodge",35);   
	       set("suit_eff_skill/sword",35);
	       set("suit_eff_skill/blade",35);
	       set("suit_eff_skill/cuff",35);
	       set("suit_eff_skill/strike",35);
	       set("suit_eff_skill/finger",35);
	       set("suit_eff_skill/claw",35);
       //------------------------------------------------------
	}
	init_sword(155);
	setup();
}
int query_autoload()
{
	return 1;
}