
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
	"liuyang-zhang" : "strike",
	"ruyi-dao" : "parry",
	"ruyi-dao" : "blade",
	"xiaoyao-qixue" : "medical",
	"literate" : 0,
]),
		([//��ң
	"beiming-shengong" : "force",
	"lingbo-weibu" : "dodge",
	"zhemei-shou" : "hand",
	"liuyang-zhang" : "strike",
	"ruyi-dao" : "parry",
	"ruyi-dao" : "blade",
	"xiaoyao-qixue" : "medical",
	"literate" : 0,
]),
		([//��ң
	"beiming-shengong" : "force",
	"lingbo-weibu" : "dodge",
	"zhemei-shou" : "hand",
	"liuyang-zhang" : "strike",
	"ruyi-dao" : "parry",
	"ruyi-dao" : "blade",
	"xiaoyao-qixue" : "medical",
	"literate" : 0,
]),
		([//��ң
	"beiming-shengong" : "force",
	"lingbo-weibu" : "dodge",
	"zhemei-shou" : "hand",
	"liuyang-zhang" : "strike",
	"ruyi-dao" : "parry",
	"ruyi-dao" : "blade",
	"xiaoyao-qixue" : "medical",
	"literate" : 0,
]),
});

string* msg = ({
"1,һ�ȹ�����,���۾�����,ħͷ",
"2,һ�ȹ�����,���۾�����,ħͷ",
"3,һ�ȹ�����,���۾�����,ħͷ",
"4,һ�ȹ�����,���۾�����,ħͷ",
"5,һ�ȹ�����,���۾�����,ħͷ",
"6,һ�ȹ�����,���۾�����,ħͷ",
"7,һ�ȹ�����,���۾�����,ħͷ",
"8,һ�ȹ�����,���۾�����,ħͷ",
"9,һ�ȹ�����,���۾�����,ħͷ",


});

void create()
{

	set_name("boss", ({ "xiaoguai", "xiaoguai" }));
	set("title", HIY "boss" NOR);
	set("gender", "����");
	set("age", 20);
	set("long","���Ǹ���������ʮ����ĺ��ӣ���üȫ�ڣ��������ݣ���һϮս�ۣ���Ȼͦ����\n");


	set("str", 50);
	set("int", 50);
	set("con", 50);
	set("dex", 50);

	set("max_qi", 100000);
	set("max_jing", 100000);
	set("neili", 100000);
	set("max_neili", 100000);
	set("jiali", 500);
	set("combat_exp", 100000000);

    set("sequence",3);//����������������
    set("lvl",200);//������������ɳ�ֵ
	 set_temp("apply/reduce_busy", 100);//����æ��
	set_temp("apply/attack", 150);//����
	set_temp("apply/defense", 150);//����
	set_temp("apply/damage", 150);//�����˺�
	set_temp("apply/unarmed_damage", 150);//�����˺�

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
	me->move("/d/xiaobaiben/fangjian2");
	 ::die();
	  }
	  else
	  if (newsequence >= 1)
	  {
		pot=50000;
		exp=50000;
	  me->add("potential",pot);
	  me->add("combat_expl",exp);
	  tell_object(me,HIR"���ɱ��"+ob->query("name")+exp+"����Ϊ��\n""������Լ�"+pot+"��Ǳ�ܡ�\n"NOR);
	  newob = new("/d/xiaobaiben/npc/bosshuxing");
		}
  
   /*	jilv= random(10);
	  if (jilv == 1)
	  {
	  objwp =new("clone/vip/book_wuliang");
	  objwp->move(environment(me));
	 message("channel:chat",HBRED"������ս"HIR"��"+ob->query("name")+"������� ����\n"NOR,users());
	  }
	  else
	  if (jilv == 2)
	  {
	  objwp =new("/d/automap4/npc/guai1");
	  objwp->move(environment(me));
	  message("channel:chat",HBRED"������ս"HIR"��"+ob->query("name")+"������� ����\n"NOR,users());

	  }
	  else
	    if (jilv == 0)
	  {
	  objwp =new("/clone/fbqhs");
	  objwp->move(environment(me));
	    message("channel:chat",HBRED"������ս"HIR"��"+ob->query("name")+"������� ����\n"NOR,users());
	  }*/

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
 distribute_skill(newob,me->query_temp("zhuangtai")+70);


    newob->set("qi", ob->query("lvl")*100);
	newob->set("max_qi",ob->query("max_qi")*100);
	newob->set("eff_qi",ob->query("max_qi")*100 );
	newob->set("jing", ob->query("max_jing")*100);
	newob->set("max_jing", ob->query("max_jing")*100);
	newob->set("neili", ob->query("max_neili")*100);
	newob->set("max_neili", ob->query("max_neili")*100);
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