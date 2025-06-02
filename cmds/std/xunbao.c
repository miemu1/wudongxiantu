// by fid
#include <ansi.h>
inherit F_DBASE;
inherit F_CLEAN_UP;
string *color=({HIR"��",HIY"��",YEL"��",HIG"��",HIC"��",HIB"��",HIM"��",HIW"��",BLK"��"});
string *unit=({"��","��","��","Ƭ","Ƭ"});
string *light=({"��"NOR,"��"NOR,"��"NOR,"��"NOR,"ϼ"NOR});
string *baowu=({
	"clone/baowu/1",
	"clone/baowu/2",
	"clone/baowu/3",
	"clone/baowu/4",
	"clone/baowu/5",
	"clone/baowu/6",
	"clone/baowu/7",
	"clone/baowu/8",
	"clone/baowu/9",
	"clone/baowu/10"
});

void create()
{
    set("name","Ѱ������");
    set("id","xbjl");
    seteuid(getuid());
}

int main(object me,string arg)
{
	string dest;
    object env;
    int sec,need,time,timedelay,kar;
	mapping exit;

    env=environment(me);

    if (!WABAO_D) return notify_fail("�ڱ����黹û���롣\n");
    if (me->is_busy()) return notify_fail("��������æ���ء�����\n");
    if (me->query("combat_exp") < 10000 ) return notify_fail("����Ϊ���㣬������ڽ�����Ѱ����\n");
    if (me->query("mud_age") < 172800 ) return notify_fail("��̫�����ˣ��ȹ�������Ѱ���ɡ�\n");
        if ( !present("skybook", me) )
         return notify_fail("��û��"+HIW"ʮ������"NOR+"����ô��Ѱ���أ�\n");
    if (!arg||arg==""||sscanf(arg,"%d",sec)!=1)
        return notify_fail("xunbao <����>\n\n��Ҫ���Ѷ���ʱ����Ѱ�ң�\n\n");
	if(!me->query_temp("xunbao"))
		         return notify_fail("��ո�Ѱ�������ȴ���һ�ΰ�\n");

    time=me->query_temp("xunbao/time");
    need=me->query_temp("xunbao/need");
    if (!need||need==0)
        {
        kar=40-me->query("kar");
        need=kar*3;
        need+=random(kar*2);
        if (need<30) need=30;
        me->set_temp("xunbao/need",need);
        }
    if (file_name(env)+".c"==WABAO_D->query("file"))
        {
        if (time<need)
            {
            timedelay=((sec+time>=need)?(need-time):sec);
            me->add_temp("xunbao/time",sec);
            }
        else
            timedelay=1;
        }
    else
        timedelay=sec;
    message_vision(HIC"$N������"+HIW"��ʮ�����顷"+HIC"������������ʼѰ����\n"NOR,me);
    me->start_busy(timedelay,timedelay);
    call_out("end_finding",timedelay,me,env);
    return 1;
}

void end_finding(object me,object env)
{
        int gain,i;
        object ob,bao;
        me->interrupt_me();
        if (!WABAO_D->query("file")) me->delete_temp("xunbao");
        if (file_name(env)+".c"!=WABAO_D->query("file")
                )
        {
        tell_object(me,HIC"���ã��㻹��һ������,Ҳ����ͱ��˽����ȵ��ˡ�\n"NOR);
        tell_room(env,HIC+me->query("name")+"���˴����������ʧ����վ��������\n"NOR,me);
        return ;
        }
        me->delete_temp("xunbao");
        WABAO_D->delete("file");
        WABAO_D->delete("desc");
        log_file("wabao",sprintf("[%s]%s wabao from %s\n",
                    ctime(time()),
                    getuid(me),
                    file_name(env)) );
        i=random(sizeof(unit));
        message_vision(HIG"ͻȻ���ӵ���ӿ��һ"+unit[i]+color[random(sizeof(color))]+
                        light[i]+HIG"��$N������������\n"NOR,me);
        gain=5000 + 100 * me->query("kar") + random(5000);
        /*me->add("xunbao/get",1);
        if (me->query("xunbao/get")>10)
                {
                tell_object(me,HIM"���Ѿ�Ѱ��̫�౦���ˣ��Ƿ�Ӧ�ÿ���Т�����һ�㣿\n"NOR);
                return;
                }*/
        switch(random(6))
        {
        case 0:
                gain=1+random(5);
                ob=new("/clone/money/gold");
                ob->set_amount(gain);
                ob->move(me);
	message("channel:chat", HIM + ZJSIZE(25)"��Ѱ�����顿"+me->query("name")+"ͨ��Ѱ���õ���"+chinese_number(gain)+"���ƽ𣡡�\n"NOR,users());
                tell_object(me,sprintf(HIY"������%s���ƽ�10ս����Ϊ��\n"NOR,
                        chinese_number(gain)));
						me->add("xunbaocshu1",1);
						me->add("zhanling/a7",10);
                break;
        case 1:
                gain=2+random(6);
						me->add("xunbaocshu1",1);
						me->add("zhanling/a7",10);
                me->add("jifeng",gain);
	message("channel:chat", HIM + ZJSIZE(25)"��Ѱ�����顿"+me->query("name")+"ͨ��Ѱ���õ���"+chinese_number(gain)+"����ȯ����\n"NOR,users());
                tell_object(me,sprintf(HIY"������%s���ȯ��10ս����Ϊ��\n"NOR,
                        chinese_number(gain)));
                break;
        case 2:
                gain=3+random(5);
						me->add("xunbaocshu1",1);
						me->add("zhanling/a7",10);
                ob=new("/clone/money/gold");
                ob->set_amount(gain);
                ob->move(me);
	message("channel:chat", HIM + ZJSIZE(25)"��Ѱ�����顿"+me->query("name")+"ͨ��Ѱ���õ���"+chinese_number(gain)+"���ƽ𣡡�\n"NOR,users());
                tell_object(me,sprintf(HIY"��õ���%s���ƽ�10ս����Ϊ��\n"NOR,
                        chinese_number(gain)));
                break;
        case 3:
                gain=2+random(5);
				me->add("yuanbao",gain);
						me->add("zhanling/a7",10);
						me->add("xunbaocshu1",1);

	message("channel:chat", HIM + ZJSIZE(25)"��Ѱ�����顿"+me->query("name")+"ͨ��Ѱ���õ���"+chinese_number(gain)+"����ʯ����\n"NOR,users());
                tell_object(me,sprintf(HIY"������%s����ʯ��10ս����Ϊ��\n"NOR,
                        chinese_number(gain)));
                break;
        default:
                gain=1;
                me->add("tianji1",gain);
						me->add("zhanling/a7",10);
						me->add("xunbaocshu1",1);

	message("channel:chat", HIM + ZJSIZE(25)"��Ѱ�����顿"+me->query("name")+"ͨ��Ѱ���ҵ��������ż��������������"+chinese_number(gain)+"������\n"NOR,users());
                tell_object(me,sprintf(HIY"��������������%s����10ս����Ϊ��\n"NOR,
                        chinese_number(gain)));
                break;
        }

    call_out ("night_appearing",1);
        return ;
}

int help(object me)
{
  write(@HELP

��Ѱ����

    ϵͳÿ��һ����ʱ�����ʾ��һ�в�ȫ�����������ʾ����ͳ�
����������������ĵط�����Ȼ��ʱ���м����ط���������һ���ģ�
�����͵��������ˣ����ҵ�����ط���Ȼ���xunbao����Ѱ����Ҫ��
ʱ�����Ե�йأ��������Ǹ�ԵԽ�ߣ���Խ���ҵ����õ��Ľ�������
���ģ�Ҳ�Ǹ�ԵԽ�ߵõ���Խ�ࡣ
    Ѱ���������ࣨ����10��������Ҫ�����������Щ�����ˣ�����
���Ҳ��������ˡ���ҪǮ�Ŀ���ȥ�죨ling����

            by fid
HELP
    );
    return 1;
}

