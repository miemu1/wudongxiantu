// ˮ䰴�֮108����

#include <ansi.h>

inherit NPC;

int ask_zhou();
int ask_back();
int inheritman(object newob,object ob,int manskills,string*manmsg,int newsequence);
string* msg = ({
"0,��ħ��,���µ�һ,��ħ",	
"1,�����,������,�ν�",
"2,�����,������,¬����",
"3,�����,�Ƕ���,����",
"4,������,������,����ʤ",
"5,������,��,��ʤ",
"6,������,����ͷ,�ֳ�",
"7,������,������,����",
"8,������,˫��,������",
"9,��Ӣ��,С���,����",
"10,�����,С����,���",
"11,�츻��,�����,��Ӧ",
"12,�윺��,���׹�,����",
"13,�����,������,³����",
"14,������,����,����",
"15,������,˫ǹ��,��ƽ",
"16,�����,û���,����",
"17,�찵��,���檕,��־",
"18,������,��ǹ��,����",
"19,�����,���ȷ�,����",
"20,������,����̫��,����",
"21,������,����,����",
"22,��ɱ��,�\����,����",
"23,��΢��,������,ʷ��",
"24,�쾿��,û����,�º�",
"25,������,���Ợ,�׺�",
"26,������,�콭��,�",
"27,�콣��,����̫�r,��С��",
"28,��ƽ��,������,�ź�",
"29,������,��������,��С��",
"30,������,�������,��˳",
"31,�����,������,��С��",
"32,������,������,����",
"33,�����,��������,ʯ��",
"34,�챩��,��ͷ��,����",
"35,�����,˫βЫ,�ⱦ",
"36,������,����,����",
"37,�ؿ���,�����ʦ,����",
"38,��ɷ��,����ɽ,����",
"39,������,��ξ�W,����",
"40,�ؽ���,����,����",
"41,������,��ľ��,��˼��",
"42,������,��ʤ��,����",
"43,��Ӣ��,��Ŀ��,��^",
"44,������,ʥˮ��,��͢��",
"45,������,���,κ����",
"46,������,ʥ������,����",
"47,������,����Ŀ,����",
"48,�ر���,Ħ�ƽ��,ŷ��",
"49,������,������,�˷�",
"50,��ǿ��,��ë��,��˳",
"51,�ذ���,������,����",
"52,�ظ���,������,����",
"53,�ػ���,������,����",
"54,������,С�º�,����",
"55,������,���ʹ�,��ʢ",
"56,�����,��ҽ,����ȫ",
"57,�ت���,���ײ�,�ʸ���",
"58,��΢��,���Ż�,��Ӣ",
"59,�ػ���,һ����,������",
"60,�ر���,ɥ����,����",
"61,���a��,����ħ��,����",
"62,�ز���,ëͷ��,����",
"63,�ؿ���,������,����",
"64,�ط���,�˱���߸,���",
"65,������,�����ʥ,����",
"66,������,��۽�,����",
"67,������,⟵���,����",
"68,�ؽ���,������,ͯ��",
"69,������,������,ͯ��",
"70,�؜���,��ᦸ�,�Ͽ�",
"71,������,ͨ��Գ,�",
"72,������,������,�´�",
"73,���L��,�׻���,�",
"74,������,�����ɾ�,֣����",
"75,������,��β�w,������",
"76,�ؿ���,�����,����",
"77,�ؘS��,⟽���,�ֺ�",
"78,�ؽ���,���,����",
"79,������,�м���,������",
"80,������,С����,�´�",
"81,�����,�ٵ���,����",
"82,��ħ��,������,����",
"83,������,������,��Ǩ",
"84,������,�����,Ѧ��",
"85,��Ƨ��,�򻢽�,����",
"86,�ؿ���,С����,��ͨ",
"87,�ع���,���E����,��¡",
"88,��ȫ��,������,����",
"89,�ض���,������,��Ԩ",
"90,�ؽ���,������,����",
"91,������,���غ���,���",
"92,���i��,Ц�滢,�츻",
"93,�ط���,���۱�,ʩ��",
"94,��ƽ��,⟱۲�,�̸�",
"95,������,һ֦��,����",
"96,��ū��,�����й�,����",
"97,�ز���,���ۻ�,����",
"98,�ؐ���,û��Ŀ,��ͦ",
"99,�س���,ʯ����,ʯ��",
"100,������,Сξ�W,����",
"101,������,ĸ���,�˴�ɩ",
"102,������,��԰��,����",
"103,��׳��,ĸҹ��,�����",
"104,������,������,������",
"105,�ؽ���,ꓵ���,������",
"106,�غ���,������,��ʤ",
"107,������,������,ʱǨ",
"108,�ع���,��ëȮ,�ξ�ס",});

void create()
{
	set_name("��ɽ�Ž�", ({ "xingxiu man", "liangshan" }));
	set("title", HIY "��ëȮ" NOR);
	set("gender", "����");
	set("age", 20);
	set("long","���Ǹ���������ʮ����ĺ��ӣ���üȫ�ڣ��������ݣ���һϮս�ۣ���Ȼͦ����\n");

	set("int", 30);
	set("str", 30);
	set("con", 30);
	set("dex", 30);

	set("qi", 6000);
	set("sequence", 108);
	set("max_qi", 5000);
	set("jing", 20000);
	set("max_jing", 20000);
	set("neili", 15000);
	set("max_neili", 15000);
	set("jiali", 250);
	set("combat_exp", 5000000);
	set("score", 20000000);

	set_skill("force", 100);
	set_skill("taixuan-gong", 100);
	set_skill("dodge", 100);
	set_skill("taixuan-gong", 100);
	set_skill("unarmed", 100);
	set_skill("taixuan-gong", 100);
	set_skill("parry", 100);

	map_skill("force", "taixuan-gong");
	map_skill("dodge", "taixuan-gong");
	map_skill("unarmed", "taixuan-gong");
	map_skill("parry", "taixuan-gong");
	
		prepare_skill("unarmed", "taixuan-gong");

	set("chat_chance_combat", 200);
	set("chat_msg_combat", ({
		(: exert_function, "powerup" :),
		(: perform_action, "xuan" :),
	(: perform_action, "jing" :),
	}) );

	set("chat_chance", 5);
	set("inquiry", ([
		"108����" :  "ˮ䰴���˵���𣿡�",
	]));

	create_family("��ɽ", 0, "�ú�");
	setup();

	carry_object("/clone/misc/cloth")->wear();
}


void die()
{
        object me = this_object()->query_last_damage_from();
        object newob,ob,jl,jl2,jl1,wuliang,dan;
		string *manmsg;
        int newsequence,manskills,i,j;
        ob = this_object();
		newsequence = ob->query("sequence")-1;
		manmsg = explode(msg[newsequence],",");
		newob = new("d/fuben/108man/npc/1");
		jl = new("clone/jifeng/putao");
			jl1 = new("clone/jifeng/dan_congmai2");
				jl2 = new("clone/jifeng/dan_congmai3");
				wuliang = new("clone/jifeng/book_wuliang");
				dan = new("clone/jifeng/dan_congmai4");
				
				
		manskills = ob->query_skill("force",1)+10;

 if (ob->query("sequence") > 72)
	  {
	    if (random(2) == 1)
   	  {
     	  tell_object(me,HIR"��ϲ������һ�����Ѻ��������飡\n"NOR);
	    jl->move(me);
		wuliang->move(me);
   	  }
   	  if (random(10) == 1)
  	  {
   	  me->add("jifeng",10);
  	  tell_object(me,HIR"��ϲ������10���ȯ��\n"NOR);
   	  }
	}
	  else
	    if (ob->query("sequence") > 32)
	  {
     	  if (random(2) == 1)
    	  {
	  tell_object(me,"��ϲ������һ����Ʒ��������\n");
	  jl1->move(me);
     	  }
	       if (random(10) == 1)
    	  {
	  me->add("jifeng",10);
	  tell_object(me,"��ϲ������10���ȯ��\n");
	       }
	  }
	  else
	 if (ob->query("sequence") < 32)
{
	  if (random(2) == 1)
	  {
	  tell_object(me,HIW"��ϲ������һ����Ʒ��������\n"NOR);
	 jl2->move(me);
	  }
	  if (random(10) == 1)
	  {
	  dan->move(me);
	  tell_object(me,HIR"��ϲ�����˼�Ʒ��������\n"NOR);
	  }
	 }
	    if (ob->query("sequence") == 1)
	  {
		  me->move("d/city/kedian");
		  ::die();
	  }
	  inheritman(newob,ob,manskills,manmsg,newsequence);
	  newob->set("long","������ɽ�ú���������"+manmsg[0]+"��"+ manmsg[2]+manmsg[3]+"��ӵ�кܸߵ����ա�"); 
	  environment(me)->set("short",manmsg[1]);
	  newob->move(environment(me));  
	 tell_object(me,ZJFORCECMD("look"));//ִ��lookָ��Ա���ҿ������ػ������Ƶı仯!
	  ::die();
}

int inheritman(object newob,object ob,int manskills,string*manmsg,int newsequence)
{
 newob->set("qi", ob->query("max_qi")+8000);
	newob->set("max_qi",ob->query("max_qi")+8000);
	newob->set("eff_qi",ob->query("max_qi")+8000);
	newob->set("jing", ob->query("max_jing")+8000);
	newob->set("max_jing", ob->query("max_jing")+8000);
	newob->set("neili", ob->query("max_neili")+8000);
	newob->set("max_neili", ob->query("max_neili")+8000);	  
	newob->set("sequence",newsequence);	 
	 newob->set("name",manmsg[3]);
	 newob->set("title",manmsg[2]);
	newob-> set_skill("force", manskills);
	newob->set_skill("taixuan-gong", manskills);
	newob->set_skill("dodge", manskills);
	newob->set_skill("taixuan-gong", manskills);
	newob->set_skill("unarmed", manskills);
	newob->set_skill("taixuan-gong", manskills);
	newob->set_skill("parry",manskills);
	return 1;
}