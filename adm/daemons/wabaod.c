// by fid
#include <ansi.h>
#define TIME 600
inherit F_DBASE;
string get_long();
void insert_blank();
void init_xunbao();

string *DIRS =({
 //               "/d/annan/",
//                "/d/city/",
//                "/d/beihai/",
                "/d/dali/",
                "/d/emei/",
////                "/d/beijing/",
//                "/d/binghuodao/",
                "/d/gumu/",
                "/d/heimuya/",
//                "/d/cangzhou/",
//                "/d/changsha/",
//                "/d/dingxiang/",
                "/d/huashan/",
//                "/d/kunlun/",
                "/d/lingjiu/",
//                "/d/guanwai/",
//                "/d/guizhou/",
//                "/d/hainan/",
//                "/d/hangzhou/",
//                "/d/quanzhou/",
//                "/d/huizhu/",
//				"/d/xiangyang/",
//                "/d/shaolin/",
//	            "/d/yueyang/",
//	            "/d/xizang/",
//				"/d/tiezhang/",
//                "/d/shenlong/",
//                "/d/taishan/",
//				"/d/taiwan/",
                "/d/taohua/",
//                "/d/tianlongsi/",
 //               "/d/village/",
                "/d/wudang/",
 //               "/d/jingzhou/",
//                "/d/kaifeng/",
//                "/d/xingxiu/",
                "/d/xuedao/",
                "/d/xueshan/",
                });

void create()
{
    seteuid(getuid());
    set("name","Ѱ������");
    set("channel_id", "Ѱ������(xunbao)");
    set("id","xunbao");
    CHANNEL_D->do_channel( this_object(), "sys", "Ѱ��ϵͳ�Ѿ�������\n");
    init_xunbao();
}

void init_xunbao()
{
    int i;
    object *user;
    user=users();
    for (i=0;i<sizeof(user);i++)
        user[i]->set_temp("xunbao",1);
    insert_blank();
	message("channel:chat", HIB"�����ء�"HIW + "������ʿ���Ϸ�ҹ�����������챦�н�������\n"NOR,users() );
	message("channel:chat", HIB"�����ء�"HIW + "������ʿ����ʱʮ���ӣ�����ֻ��һ�Σ���λ��������ʲô�ء�\n"NOR,users() );

	//message("channel:chat",HIB"\n�����ء�"NOR HIW"��ҩʦ���Ϸ�ҹ�����������챦�н�������\n"NOR,users());
    //message("vision",HIB"\n�����ء�"NOR WHT"��ҩʦ���Ϸ�ҹ�����������챦�н�������\n\n"NOR,users());
    return;
}

void insert_blank()
{
    string long,desc;
    int i,begin,lost,sep,left;
//     object room;

    remove_call_out("init_xunbao");
    call_out("init_xunbao",TIME);
    while(1){
        long=get_long();
        if (long!="") break;
        }

    begin=random((strlen(long)-60)/2)*2;
    desc=long[begin..begin+60];
    switch(random(11000)%11)
        {
        case 0: case 1:
                lost=10;
                break;
        case 2: case 3: case 4:
                lost=9;
                break;
        case 5: case 6: case 7:
                lost=8;
                break;
        case 8: case 9:
                lost=7;
                break;
        case 10:
                lost=6;
        }
    sep=30/lost;
    left=30-sep*lost;
    for (i=0;i<lost;i++)
        {
        begin=(sep*i+random(sep))*2;
        desc[begin..begin+1]="��";
        }
    if (left>4)
        {
        begin=(30-left+random(left))*2;
        desc[begin..begin+1]="��";
        }
    WABAO_D->set("desc",desc);
    return ;
}

string get_long()
{
      int i;
    string dir,file,*files,long,*lines,name;
    object room;
    dir=DIRS[random(sizeof(DIRS))];
    files=get_dir(dir);
    file=dir+files[random(sizeof(files))];
    if (!room=find_object(file)) if (!room=load_object(file)) return "";
    if (!inherits(ROOM,room)) return "";
    else
        {
        long=room->query("long");
		name=room->query("short");
        lines=explode(long,"\n");
        long="";
		long += name;
        for (i=0;i<sizeof(lines);i++) long+=lines[i];
        if (strlen(long)<60) return "";
        for (i=0;i<strlen(long);i++)
                {
                if(long[i]<128)
                return "";
                }
		WABAO_D->set("short",name);
        WABAO_D->set("file",file);
        return long;
        }
}

