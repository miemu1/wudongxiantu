

#include <ansi.h>

inherit NPC;

static int ask_zhou();
static int ask_back();
static int inheritman(object newob,object ob,int manskills,string*manmsg,int newsequence);
int distribute_skill(object ob,int skill_level);

mapping *skill_map = ({
([//��ң
	"beiming-shengong" : "force",
	"lingbo-weibu" : "dodge",
	"zhemei-shou" : "hand",
	"dragon-strike" : "strike",
	"qishang-quan" : "parry",
	"kongming-quan" : "unarmed",
	"ruyi-dao" : "blade",
	"dragon-strike" : "strike",
	"xiaoyao-qixue" : "medical",
	"literate" : 0,
]),
		([//��ң
	"beiming-shengong" : "force",
	"lingbo-weibu" : "dodge",
	"zhemei-shou" : "hand",
	"kongming-quan" : "unarmed",
	"dragon-strike" : "strike",
	"qishang-quan" : "parry",
	"ruyi-dao" : "blade",
	"xiaoyao-qixue" : "medical",
	"literate" : 0,
]),
		([//��ң
	"beiming-shengong" : "force",
	"lingbo-weibu" : "dodge",
	"kongming-quan" : "unarmed",
	"zhemei-shou" : "hand",
	"dragon-strike" : "strike",
	"qishang-quan" : "parry",
	"ruyi-dao" : "blade",
	"xiaoyao-qixue" : "medical",
	"literate" : 0,
]),
		([//��ң
	"beiming-shengong" : "force",
	"lingbo-weibu" : "dodge",
	"zhemei-shou" : "hand",
	"kongming-quan" : "unarmed",
	"dragon-strike" : "strike",
	"qishang-quan" : "parry",
	"ruyi-dao" : "blade",
	"xiaoyao-qixue" : "medical",
	"literate" : 0,
]),

});

string* msg = ({

"1,һ�ȹ�����,���۾�����,��ħ",
"2,һ�ȹ�����,���۾�����,���",
"3,һ�ȹ�����,���۾�����,С��",
"4,һ�ȹ�����,���۾�����,����",
"5,һ�ȹ�����,���۾�����,Ѫħ",
"6,һ�ȹ�����,���۾�����,���",
"7,һ�ȹ�����,���۾�����,ħ��",
});

void create()
{

	set_name("��ʬ", ({ "xiaoguaiu", "xiaoguai" }));
	set("title", HIY "����" NOR);
	set("gender", "����");
	set("age", 20);
	set("long","���ǿ��Ը����ħ�û����һ��ʵ���ͻ��ǿһ�㡣\n");


	set("str", 30);
	set("int", 30);
	set("con", 30);
	set("dex", 30);

	set("max_qi", 20000);
	set("max_jing", 10000);
	set("neili", 10000);
	set("max_neili", 10000);
	set("jiali", 30);
	set("combat_exp", 10000000);

    set("sequence",7);//����������������
    set("lvl",100);//������������ɳ�ֵ
	 set_temp("apply/reduce_busy", 100);//����æ��
	set_temp("apply/attack", 300);//����
	set_temp("apply/defense", 100);//����
	set_temp("apply/damage", 300);//�����˺�
	set_temp("apply/unarmed_damage", 300);//�����˺�

	setup();
	carry_object("/clone/misc/cloth")->wear();
}


void die()
{
        object me = this_object()->query_last_damage_from();
        object newob,ob,jl,jl2,jl1,objwp;
		string *manmsg;
        int newsequence,manskills,pot,jilv;
		int exp;
        ob = this_object();
		newsequence = ob->query("sequence")-1;
		manmsg = explode(msg[newsequence],",");

	  if (newsequence <= 1)
	  {
		  me->move("/d/sishenfuben/fangjian");
		  ::die();
	
	  }
	  else
	  if (newsequence >= 1)
	  {
		pot=10000;
		exp=10000;
	  me->add("potential",pot);
	  me->add("combat_expl",exp);
	  tell_object(me,HIW"���ɱ��"+ob->query("name")+exp+"����Ϊ��\n""������Լ�"+pot+"��Ǳ�ܡ�\n"NOR);
	  newob = new("/d/sishenfuben/npc/npcshuxing");
		}
  
	jilv= random(15);
	  if (jilv == 1)
	  {
	  objwp =new("d/sishenfuben/obj/book_wuliang");
	  objwp->move(environment(me));
	 message("channel:chat",HIW"��������ս��"HIR"��"+me->query("name")+"��ɱħ�� ������������\n"NOR,users());
	  }
	  else
	  if (jilv == 2)
	  {
	  objwp =new("d/sishenfuben/obj/putao");
	  objwp->move(environment(me));
	  message("channel:chat",HIW"��������ս��"HIR"��"+me->query("name")+"��ɱħ�� ��������\n"NOR,users());
	  }
	  else
	    if (jilv == 0)
	  {
	  objwp =new("d/sishenfuben/obj/book_wuliang");
	  objwp->move(environment(me));
	    message("channel:chat",HIW"��������ս��"HIR"��"+me->query("name")+"��ɱħ�� ������������\n"NOR,users());
	  }
	   else
	    if (jilv == 3)
	  {
	  objwp =new("d/sishenfuben/obj/tianling");
	  objwp->move(environment(me));
	    message("channel:chat",HIW"��������ս��"HIR"��"+me->query("name")+"��ɱħ�� �������鵤\n"NOR,users());
	  }
	   else
	    if (jilv == 4)
	  {
	  objwp =new("d/sishenfuben/obj/tianling");
	  objwp->move(environment(me));
	    message("channel:chat",HIW"��������ս��"HIR"��"+me->query("name")+"��ɱħ�� �������鵤\n"NOR,users());
	  }
	   else
	    if (jilv == 5)
	  {
	  objwp =new("d/sishenfuben/obj/dan_chongmai2");
	  objwp->move(environment(me));
	    message("channel:chat",HIW"��������ս��"HIR"��"+me->query("name")+"��ɱħ�� ������Ʒ������\n"NOR,users());
	  }
	    else
	    if (jilv == 6)
	  {
	  objwp =new("d/sishenfuben/obj/putao");
	  objwp->move(environment(me));
	    message("channel:chat",HIW"��������ս��"HIR"��"+me->query("name")+"��ɱħ�� ��������\n"NOR,users());
	  }
	  else
	     if (jilv == 7)
	  {
	  objwp =new("d/sishenfuben/obj/putao");
	  objwp->move(environment(me));
	    message("channel:chat",HIW"��������ս��"HIR"��"+me->query("name")+"��ɱħ�� ��������\n"NOR,users());
	  }
	  else
	     if (jilv == 8)
	  {
	  objwp =new("d/sishenfuben/obj/putao");
	  objwp->move(environment(me));
	    message("channel:chat",HIW"��������ս��"HIR"��"+me->query("name")+"��ɱħ�� ��������\n"NOR,users());
	  }
	   else
	    if (jilv == 9)
	  {
	  objwp =new("d/sishenfuben/obj/dan_chongmai2");
	  objwp->move(environment(me));
	    message("channel:chat",HIW"��������ս��"HIR"��"+me->query("name")+"��ɱħ�� ������Ʒ������\n"NOR,users());
	  }
	  else
	    if (jilv == 10)
	  {
	  objwp =new("d/sishenfuben/obj/dan_chongmai3");
	  objwp->move(environment(me));
	    message("channel:chat",HIW"��������ս��"HIR"��"+me->query("name")+"��ɱħ�� ������Ʒ������\n"NOR,users());
	  }
	  else
	    if (jilv == 11)
	  {
	  objwp =new("d/sishenfuben/obj/dan_chongmai2");
	  objwp->move(environment(me));
	    message("channel:chat",HIW"��������ս��"HIR"��"+me->query("name")+"��ɱħ�� ������Ʒ������\n"NOR,users());
	  }
	  

	  if (objectp(newob)&&objectp(ob)&&sizeof(manmsg)&&newsequence)
	  {
	  inheritman(newob,ob,manskills,manmsg,newsequence);
	  environment(ob)->set("short",manmsg[1]);
	  newob->move(environment(ob));
	 tell_object(me,ZJFORCECMD("look"));//ִ��lookָ��Ա���ҿ������ػ������Ƶı仯!
	 }
	  ::die();
}
//��Ҫע�⣬���ô˺�����Ҫ��֤�������ͬʱ���ڡ�
int inheritman(object newob,object ob,int manskills,string*manmsg,int newsequence)
{
object me = this_object()->query_last_damage_from();
 distribute_skill(newob,me->query_temp("zhuangtai")+50);

    newob->set("qi", ob->query("lvl")*50);
	newob->set("max_qi",ob->query("max_qi")*2);
	newob->set("eff_qi",ob->query("max_qi")*2 );
	newob->set("jing", ob->query("max_jing")*2);
	newob->set("max_jing", ob->query("max_jing")*2);
	newob->set("neili", ob->query("max_neili")*2);
	newob->set("max_neili", ob->query("max_neili")*2);
	newob->set("sequence",newsequence);
	
	 newob->set("name",manmsg[3]);
	 newob->set("title",manmsg[2]);
	newob->set("lvl",ob->query("lvl")+120);
	newob->set_temp("apply/jiali", ob->query("lvl"));
	newob->set_temp("apply/attack", ob->query("lvl"));
	newob->set_temp("apply/defense", ob->query("lvl"));
	newob->set_temp("apply/damage", ob->query("lvl")*3/2);
	newob->set_temp("apply/unarmed_damage", ob->query("lvl")*3/2);
	return 1;
}

int distribute_skill(object ob,int skill_level)
{
int ran,size,i;
string *skills;
	ran = random(sizeof(skill_map));
	size = sizeof(skill_map[ran]);
	skills = keys(skill_map[ran]);

	for(i = 0; i < size; i++)
	{
		if (!skill_map[ran][skills[i]])
		{
			ob->set_skill(skills[i], skill_level);
		}
		else
		{
			ob->set_skill(skills[i], skill_level);
			ob->set_skill(skill_map[ran][skills[i]], skill_level);
			ob->map_skill(skill_map[ran][skills[i]], skills[i]);
		}
	}
	return 1;
}