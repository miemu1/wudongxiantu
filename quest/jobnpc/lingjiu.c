// /NPC tonglao.c

#include <ansi.h>
inherit NPC;
//inherit F_SKILL;

string* nm1 = ({
"��","Ǯ","��","��","��","��","֣","��","��","��","��","��",
"��","��","��","��","��","��","��","��","��","��","ʩ","��",
"��","��","��","��","��","κ","��","��","��","л","��","��",
"��","ˮ","�","��","��","��","��","��","��","��","��","��",
"³","Τ","��","��","��","��","��","��","ɵ","��","Ԭ","��",
"��","��","ʷ","��","��","��","�","Ѧ","��","��","��","��",
"��","��","��","��","��","��","��","��","��","��","ʱ","��",
"Ƥ","��","��","��","��","��","Ԫ","��","��","ӯ","ƽ","��",
"��","��","Ф","��","Ҧ","��","տ","��","��","ë","��","��",
"��","��","��","��","��","��","��","��","̸","��","é","��",
"��","��","��","��","��","ף","��","��","��","��","��","��",
"��","��","֧","��","��","��","¬","Ӣ","��","��","��","˧",
"˾��","�Ϲ�","ŷ��","�ĺ�","���","����","����","����","�ʸ�",
"ξ��","����","�̨","����","����","���","����","����","̫��",
"����","����","����","ԯ��","���","����","����","����","Ļ��",
"˾ͽ","ʦ��","��","��ľ","����","����","���","����","����",
"����","��ֺ","�й�","�׸�","����","����","�ַ�","��۳","Ϳ��",
"��ǧ","����","����","�Ϲ�","����","�麣","����","΢��","����",
"����","����","����","����","�Ϲ�",
"��","��","��","��","��","��","��","Ĳ","��","��","ī","��",
"��","��","��","��","١","��","��","��","��","��","��","��",
"��","ʯ",
});

string* id = ({
"zhao","qian","sun","li","zhou","wu","zhen","wang","feng","chen","zhu","wei",
"jiang","shen","han","yang","zhu","qing","you","xu","he","lu","shi","zhang",
"kong","cao","yan","hua","jin","wei","tao","jiang","qie","xie","zhou","yu",
"bo","shui","dou","zhang","yun","su","pan","ge","xi","fan","peng","lang",
"lu","wei","chang","ma","miao","feng","hua","fang","sha","ren","yuan","liu",
"deng","bao","shi","tang","fei","lian","chen","xue","lei","he","ni","tang",
"teng","yin","luo","hua","hao","wu","an","chang","le","dai","shi","fu",
"pi","bian","qi","kang","wu","yu","yuan","po","gu","ying","ping","huang",
"he","mu","xiao","yin","yao","shao","zhan","wang","qi","mao","yu","di",
"mi","bei","ming","zang","ji","fu","cheng","dai","tan","song","mao","pang",
"xiong","ji","su","qu","xiang","zhu","dong","liang","fan","hu","ling","ho",
"yu","wan","zhi","ke","jiu","guan","lu","ying","qiu","hou","yue","suai",
"sima","shangguan","ouyang","xiahou","zhuge","wenren","dongfang","helian","huangpu",
"weichi","gongyang","zhantai","gongye","zongzheng","puyang","chunyu","shanyu","taishu",
"shentu","gongshun","zhongshun","xuanyuan","linghu","zhongli","yuwen","changshun","murong",
"situ","shikong","zhuankong","duanmu","wuma","gongxi","qidiao","lezheng","xiangsi",
"gongliang","tuozhi","jiagu","zaifu","guliang","chujing","yanfa","ruye","tuqin",
"duanqian","baili","dongguo","nanguo","huyan","guihai","yangshe","weisheng","liangqiu",
"zuoqiu","dongmen","ximen","baishang","nangong",
"gou","kang","kuang","hou","you","qing","shang","mo","she","er","mo","ha",
"qiao","nian","ai","yang","dong","di","wu","yan","fu","kai","zong","zong",
"lin","shi",
});

string* nm2 = ({
"��","Т","��","��","��","��","��","��","��","��","��","»","��","С","��",
"��","��","��","��","��","��","��","֮","��","��","ʱ","��","��","��","��",
"��","��","��","��","��","��","��","��","Ϊ","��","","","","","","","","",
"","","","","","","","","","","","","","",
});

string* nm4 = ({      //Ů��ר��
"��","��","��","��","��","��","��","��","��","��","��",
"��","��","�","��","��","��","��","��","��","��","��",
"ٻ","Ƽ","��","ϼ","��","��","��","Ӣ","��","��","��",
"��",
});

void create()
{
   int i = random(sizeof(nm1));
   set_name(nm1[i]+nm2[random(sizeof(nm2))]+nm4[random(sizeof(nm4))], ({id[i]}));
   set("per",37);
	set("gender", "Ů��");
	set("age", 22);
	set("shen_type",0);
	set("attitude", "peaceful");

	set("str", 25);
	set("int", 35);
	set("con", 40);
	set("dex", 40);

	set("qi", 5000);
	set("max_qi", 5000);
	set("jing", 4000);
	set("max_jing", 4000);
	set("neili", 14000);
	set("max_neili", 14000);
	set("jiali", 100);

	set("combat_exp", 2500000);
	set("score", 200000);
	set_skill("yangyanshu", 200);
	set_skill("force", 200);
	set_skill("unarmed", 250);
	set_skill("dodge", 250);
	set_skill("parry", 250);
	set_skill("hand",250);
	set_skill("strike", 250);
        set_skill("sword",150);

	set_skill("wuzhan-mei",300);
	set_skill("zhemei-shou",300);
	set_skill("liuyang-zhang",300);
        set_skill("tianyu-qijian",300);
	set_skill("yueying-wubu",300);
	set_skill("bahuang-gong", 300);

	map_skill("force", "bahuang-gong");
	map_skill("strike","liuyang-zhang");
	map_skill("dodge", "yueying-wubu");
	map_skill("unarmed", "liuyang-zhang");
        map_skill("strike","liuyang-zhang");
	map_skill("hand", "zhemei-shou");
	map_skill("parry", "liuyang-zhang");
        map_skill("sword","tianyu-qijian");

        prepare_skill("hand","zhemei-shou");
	prepare_skill("strike","liuyang-zhang");
        set("chat_chance_combat", 90);
        set("chat_msg_combat", ({
                (: exert_function, "powerup" :),
                (: exert_function, "powerup" :),
                (: perform_action, "sword.kuangwu" :),
                (: perform_action, "sword.kuangwu" :),
                (: perform_action, "sword.san" :),
                (: perform_action, "sword.san" :),
                (: perform_action, "sword.yushijufen" :),
                (: perform_action, "sword.yushijufen" :),                
                (: perform_action, "dodge.yueguangruying" :),                
                (: perform_action, "dodge.yueguangruying" :),                
        }));
	create_family("���չ�",2, "��ʦ����");
	setup();
	carry_object("/clone/weapon/gangjian")->wield();
	carry_object("/d/lingjiu/obj/qingyi")->wear();
        carry_object("/d/lingjiu/obj/doupeng")->wear();
}
void init()
{
        remove_call_out("leave");
        call_out("leave",120);
}

void leave()
{
        object ob = this_object();
        if (!ob->is_fighting()) {
                message_vision(this_object()->query("name") + "���·�ߵ��Ӳݣ������ˡ�\n" NOR,this_object());
                destruct(this_object());
                }
        else call_out("leave",30);
}
void die()
{
int i,pot,exp;
	object killer;
	exp= random(80)+80;
	pot= exp/3;
	if(objectp(killer = query_temp("last_damage_from")))
        	tell_object(killer,"�㱻������\n"+chinese_number(exp)+"��ʵս��Ϊ\n"
		+chinese_number(pot)+"��Ǳ��\n");
if (killer)
{
	killer->add("combat_exp",exp);
	killer->add("potential",pot);
}
	::die();

return ;
}