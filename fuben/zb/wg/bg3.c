// m_jia.c

#include <ansi.h>

#include <armor.h>

inherit S_ROBE;


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
	w_name=HIR "���ߡ��·�" NOR;
        }
        if (!me->query("jiajia/id"))
        {
	w_id="Wu Zheo3";
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

        set("material", "cloth");
	set_name(w_name, ({w_id}));
	set("unit", "��");
		set("long", HIC"�������޶���"NOR"����ϵ��								
"HIG"����װ�ӳɣ��������ܵȼ�+100��"NOR"\n");
	set("value",1000);
	set("armor_prop/armor", 1000+lv1+lv2+lv3);
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
	set("armor_type","cloth");
		set("material", "fur");
				 set("suit",HIR"������װ"NOR);  //��װ����
		set("suit_lvl",9);	     //��װ�ȼ�
		set("suit_count",9);	   //��װ��������
	      //��װ������
		set("suit_mod/arrmor","���ߡ�����");
		set("suit_mod/finger","���ߡ���ָ");
//		set("suit_mod/hands","���ߡ�����");
		set("suit_mod/head","���ߡ�ͷ��");
		set("suit_mod/neck","���ߡ�����");
		set("suit_mod/pants","���ߡ�����");
		set("suit_mod/boots","���ߡ���ѥ");
		set("suit_mod/cloth","���ߡ��·�");
//		set("suit_mod/surcoat","���ߡ�����");
//		set("suit_mod/shield","���ߡ�����");
		set("suit_mod/waist","���ߡ�����");
		set("suit_mod/wrists","���ߡ�����");
	    //��װȫ�������츳Ч��  //����һ�����ǵڶ������Ե�������������
		set("suit_eff/constitution",15);      //3��
		set("suit_eff/spirituality",15);      // 5��
		set("suit_eff/intelligence",15);      //7��
		set("suit_eff/strength",15);      //9��
	       //��װȫ�����Ӽ���Ч����һ����
		set("suit_eff_skill/force",100+me->query("taozhuang/lv"));   //һ��
                set("suit_eff_skill/dodge",100+me->query("taozhuang/lv"));
                set("suit_eff_skill/parry",100+me->query("taozhuang/lv"));
                set("suit_eff_skill/unarmed",100+me->query("taozhuang/lv"));
                set("suit_eff_skill/cuff",100+me->query("taozhuang/lv"));
                set("suit_eff_skill/strike",100+me->query("taozhuang/lv"));
                set("suit_eff_skill/finger",100+me->query("taozhuang/lv"));
                set("suit_eff_skill/hand",100+me->query("taozhuang/lv"));
                set("suit_eff_skill/claw",100+me->query("taozhuang/lv"));
                set("suit_eff_skill/sword",100+me->query("taozhuang/lv"));
                set("suit_eff_skill/blade",100+me->query("taozhuang/lv"));
                set("suit_eff_skill/staff",100+me->query("taozhuang/lv"));
                set("suit_eff_skill/hammer",100+me->query("taozhuang/lv"));
                set("suit_eff_skill/club",100+me->query("taozhuang/lv"));
                set("suit_eff_skill/whip",100+me->query("taozhuang/lv"));
	setup();
}



