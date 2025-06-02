// m_jia.c

#include <ansi.h>

#include <armor.h>

inherit S_WRISTS;


int duanlian(object weapon);
int do_hui(object weapon);


string query_autoload() { return 1 + ""; }	//autoload weapon

void init()
{
        add_action("do_duanlian","lianjia");
	add_action("do_hui","huijia");
	add_action("do_levelup","jijia");
}


void create()
{
	object me;
	string w_name,w_id,w_or;
	int w_lv;
	int lv1,lv2,lv3;
	
	me = this_player();
//��������
	w_name=me->query("jiajia/name");
	w_id = "my "+me->query("jiajia/id");
	w_or = me->query("jiajia/or");
	w_lv = me->query("jiajia/lv");
	lv1=me->query("jinjie/s1")*500;
	lv2=me->query("guizhen")*1000+me->query("zhengdao/s1")*100000+me->query("feisheng/s1")*50000000;
	
	lv3=(me->query("jinjie/s2"));		
        if (!me->query("jiajia/name"))
        {
	w_name=HIC "���п� �� ��" NOR;
        }
        if (!me->query("jiajia/id"))
        {
	w_id="yzk7";
        }
        if (!me->query("jiajia/or"))
        {
	w_or="ǧ����ľ";
        }
        if (!me->query("jiajia/lv"))
        {
	w_lv=1;
        }
        if (me->query("jiajia/lv",1) > 200)
        {
	w_lv=200;
        }

        set("material", "fur");
	set_name(w_name, ({w_id}));
	set("unit", "��");
		set("long", HIC"�������޶���"NOR"�������п�ϵ��								
"HIG"����װ�ӳɣ��������ܵȼ�+150��������1500��"NOR"\n");
	set("value",1000);
	set("armor_prop/armor", 150);
	set("armor_prop/unarmed_damage", 150+lv1+lv2+lv3);
	set("armor_prop/damage", 150+lv1+lv2+lv3);	
	set("no_get",1);
	set("no_drop",1);
	set("no_put",1);
	set("armor_prop/baoji", w_lv * 2);
					set("no_drop", 1);
				set("no_sell", 1);
				set("no_steal", 1);
                set("no_put", 1);
                set("no_give", 1);
	set("no_beg",1);
	set("no_steal",1);
	set("ownmake",1);
	set("material", "fur");

	switch(w_or)
		{
		case "ǧ����ľ" :
			set_weight(500);
			set("material", "fur");
			break;
		case "���׽�ĸ" :
			set_weight(1000);
			set("material", "fur");
			break;
		case "��˿����" :
			set_weight(30);
			set("material", "fur");
			break;
		default :
		}
	set("unit", "��");
	if( me->query("jia/wear_msg"))
		set("wear_msg", me->query("jia/wear_msg")+"\n");
	else
		set("wear_msg", "$N����"+w_name+"�����ϡ�\n");
	if( me->query("jia/unequip_msg"))
		set("unequip_msg", me->query("jia/unequip_msg")+"\n");
	else
		set("unequip_msg", "$N���ϵ�"+w_name+"����������գ�ۼ���Ȼ����Ӱ�١�\n");
	set("armor_type","wrists");
		set("material", "fur");
				 set("suit",HIR"���п�"NOR);  //��װ����
		set("suit_lvl",8);	     //��װ�ȼ�
		set("suit_count",8);	   //��װ��������
	      //��װ������
		set("suit_mod/arrmor","���пͼ�");
		set("suit_mod/finger","���пͽ�");
//		set("suit_mod/hands","���п���");
		set("suit_mod/head","���пͿ�");
		set("suit_mod/neck","���п���");
		set("suit_mod/pants","���п���");
		set("suit_mod/boots","���п�ѥ");
		set("suit_mod/cloth","���п���");
//		set("suit_mod/surcoat","���п���");
//		set("suit_mod/shield","���пͶ�");
		set("suit_mod/waist","���п���");
		set("suit_mod/wrists","���п���");
	    //��װȫ�������츳Ч��  //����һ�����ǵڶ������Ե�������������
		set("suit_eff/constitution",150);      //3��
		set("suit_eff/spirituality",150);      // 5��
		set("suit_eff/intelligence",150);      //7��
		set("suit_eff/strength",150);      //9��
	       //��װȫ�����Ӽ���Ч��
		set("suit_eff_skill/force",150+me->query("taozhuang/lv"));   //һ��
                set("suit_eff_skill/dodge",150+me->query("taozhuang/lv"));
                set("suit_eff_skill/parry",150+me->query("taozhuang/lv"));
                set("suit_eff_skill/unarmed",150+me->query("taozhuang/lv"));
                set("suit_eff_skill/cuff",150+me->query("taozhuang/lv"));
                set("suit_eff_skill/strike",150+me->query("taozhuang/lv"));
                set("suit_eff_skill/finger",150+me->query("taozhuang/lv"));
                set("suit_eff_skill/hand",150+me->query("taozhuang/lv"));
                set("suit_eff_skill/claw",150+me->query("taozhuang/lv"));
                set("suit_eff_skill/sword",150+me->query("taozhuang/lv"));
                set("suit_eff_skill/blade",150+me->query("taozhuang/lv"));
                set("suit_eff_skill/staff",150+me->query("taozhuang/lv"));
                set("suit_eff_skill/hammer",150+me->query("taozhuang/lv"));
                set("suit_eff_skill/club",150+me->query("taozhuang/lv"));
                set("suit_eff_skill/whip",150+me->query("taozhuang/lv"));
	setup();
}



