// bossd.c

#include <ansi.h>

inherit F_DBASE;
inherit F_SAVE;

// ��ʼ��BOSSϵͳ
#define REFRESH_INTERVAL	10 * 3600

string *story_name;
static string *lvboss_list = ({
	"/adm/daemons/lvboss/feizei",
	"/adm/daemons/lvboss/taofan",
	"/adm/daemons/lvboss/hanfei",
	"/adm/daemons/lvboss/dadao",
	"/adm/daemons/lvboss/kuangmo",
	"/adm/daemons/lvboss/xueshi",
	"/adm/daemons/lvboss/mowei",
	"/adm/daemons/lvboss/xuemo",
	"/adm/daemons/lvboss/mozun",
	"/adm/daemons/lvboss/moshen",
});
mapping history;
int last_update = 0;
int last_boss = 0;

static mapping boss_place;
static int step;
int qilin_times = 0;
int last_qilin = 0;

string query_save_file()
{
	return DATA_DIR "newbossd";
}

void set_qilin(int times) { qilin_times = times; }

int query_qilin() { return qilin_times; }

void set_last_qilin(int time) { last_qilin = time; }

int query_last_qilin() { return last_qilin; }

void create()
{
	seteuid(ROOT_UID);
	set("channel_id", "��BOSS����");
	CHANNEL_D->do_channel( this_object(), "sys", "��BOSSϵͳ�Ѿ�������");

	// �ָ�BOSS����״��
	restore();

	if (! mapp(boss_place))
		boss_place = ([ ]);

	set_heart_beat(20);
}

void heart_beat()
{
	object npc;
	mixed t;
	int i;
	string pp,*p;
	int time = time();

	p = ({
		"/d/city/beidajie2",
		"/d/xiangyang/southjie1",
		"/d/changan/qinglong1",
		"/d/hangzhou/road11",
		"/d/beijing/yong_2",
		"/d/city3/southroad2",
		"/d/suzhou/xidajie2",
		"/d/dali/shizilukou",
		"/d/lingzhou/dongdajie",
		"/d/fuzhou/dongxiaojie",
	});
	t = localtime(time);
/*
	if( (t[2]%2==0) && (t[1]==0) && (last_boss/3600 != time/3600))
	{//ÿ2��Сʱ����ˢ�µȼ�boss
		p = ({ "����" });
		for(i=0;i<sizeof(lvboss_list);i++)
		{
			npc = new(lvboss_list[i]);
			npc->random_place(p);
			pp = MAP_D->query_map_short(env(npc));
			p += ({ pp });
			boss_place[pp] = npc;
			message("shout", HBCYN+" "+npc->query("name")+" "+NOR"��"+pp+"һ����û���������ģ�"NOR"\n", users(), ({}));
		}
		CHANNEL_D->do_channel(this_object(), "chat","����boss�ֲ�����ɣ���������Ѱ�ң�");
		last_boss = time;
	}

	if( (t[2]>=18) && (t[1]==0) && (last_qilin/3600 != time/3600))
	{//ÿСʱ����ˢ������
		npc = new("/clone/shizhe/nianshou");
		pp = p[random(sizeof(p))];
		npc->move(pp);
		message("shout", HBCYN+" "+npc->query("name")+" "+NOR"��"+environment(npc)->query("short")+"��û���������ģ�"NOR"\n", users(), ({}));
		CHANNEL_D->do_channel(this_object(), "chat","������Ϯ��Σ�����գ����Ҿ���Ѱ�Ҳ����ϣ�");
		last_qilin = time;
	}
*/
}

int clean_up()
{
	return 1;
}
