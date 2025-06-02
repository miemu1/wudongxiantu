/*�̶������ϵͳ�����ڹ���ÿ��ÿ�ܶ�ʱ���������֪ͨ
�ܣ�
  1����̨���           20:00-23:00  ��������
  2������ս��           19:30-22:30  ��������
  3����ս֮����Զ��   20:00-21:30  ��Ҫ����
  4����������ս         20:30-21:30  ��Ҫ����
  5�����ɴ���ս         20:30-22:00  ��Ҫ����
     �ͷ���ĩ�       20:00-23:59  ��������
  6����ս֮����Զ��   20:00-21:30  ��Ҫ����
     ����ս��           13:00-20:00  ��������
     �ͷ���ĩ�       00:00-23:59  ��������
  7����������ս         20:30-21:30  ��Ҫ����
     ���ɴ���ս         20:30-22:00  ��Ҫ����
     �ͷ���ĩ�       00:00-23:59  ��������
*/
#pragma optimize
#pragma save_binary

inherit F_SAVE;
inherit F_DBASE;

#include <ansi.h>

#define MEMBER_D     "/adm/daemons/memberd"
#define STR_SPRINTF    "%-10s%-20s%-20s%-20s\n"

// ��¼�ܻ��ʾ����Ϣ�������ظ�����
nosave string strshow = "";
// ��¼time��Ӧ������
nosave int current_day = 0;

// ��������
public string get_week_num(int dtime);
public void show_week_huodong(string sday);
public void do_channel(string ch, string msg);
public int can_start_huodong(string huodong);

// ͨ��ctime()���� Fri Dec 31 17:04:17 2010 ȡ��һ���ո�ǰ��
nosave mapping week_time = ([
        "Mon"  : "1", 
        "Tue"  : "2",
        "Wed"  : "3",
        "Thu"  : "4",
        "Fri"  : "5",
        "Sat"  : "6",
        "Sun"  : "7",
]);

// ������ʾ�Ļ�б���������㣬������ʾ
nosave mapping huodong_list = ([
        "1"   :  sprintf(STR_SPRINTF, "��һ", "��̨���", "19:00-23:00", "help biwu"),
        
        "2"   :  sprintf(STR_SPRINTF, "�ܶ�", "����ս��", "19:00-20:30", "help war_free"),
        
        "3"   :  sprintf(STR_SPRINTF, "����", "����Զ��", "20:00-21:30", "help league.war"),
        
        "4"   :  sprintf(STR_SPRINTF, "����", "��������ս", "21:30-22:30", "help xywar"),
        
        "5"   :  sprintf(STR_SPRINTF, "����", "�ͷ���ĩ�", "20:00-23:59", "help wkgift") +
                 sprintf(STR_SPRINTF, "    ", "���ɴ���ս", "20:00-21:30", "help league.fight"),
                 
        "6"   :  sprintf(STR_SPRINTF, "����", "�ͷ���ĩ�", "00:00-23:59", "help wkgift") +
                 sprintf(STR_SPRINTF, "    ", "����ս��", "13:00-20:00", "help war_free") +
                 sprintf(STR_SPRINTF, "    ", "����Զ��", "20:00-21:30", "help league.war"),

        "7"   :  sprintf(STR_SPRINTF, "����", "�ͷ���ĩ�", "00:00-23:59", "help wkgift") +
                 sprintf(STR_SPRINTF, "    ", "��������ս", "21:30-22:30", "help xywar") +
                 sprintf(STR_SPRINTF, "    ", "���ɴ���ս", "20:00-21:30", "help league.fight"),
]);

// ��ʾ���е��ܻ��ָ��ĳ�ջ
public void show_week_huodong(string sday)
{
        string str;
        int i;

        str = sprintf(HIC + STR_SPRINTF + NOR, "���", "���", "ʱ��", "�����ļ�"); 
        str += "=-----------------------------------------------------------------------------=\n";
        
        if (sday != "all")
        {
                str += HIG + huodong_list[sday] + NOR;
        }
        else
        {
                if (! sizeof(strshow) || current_day != time() / 86400 )
                {
                        strshow = "";
                        for(i = 0; i < sizeof(huodong_list); i ++)
                        {
                                if (get_week_num(time()) == sprintf("%d", i+1))
                                        strshow += HIR + huodong_list[sprintf("%d", i+1)] + NOR;
                                else
                                {
                                        if ((i+1)%2==0) // �ֵ�˫����ɫ
                                                strshow += HIG + huodong_list[sprintf("%d", i+1)] + NOR;
                                        else
                                                strshow += HIY + huodong_list[sprintf("%d", i+1)] + NOR;
                                }
                        }
                        current_day = time() / 86400;
                }
                str += strshow;
        }
        str += "=-----------------------------------------------------------------------------=\n";
        if (sday == "all")
        {
                str += HIR "��ɫ���ֱ�ʾ����Ļ��\n" NOR; 
                str =  "\n" HIY + "���׻�ÿ�ջ�б�  -- ��ӭ���롿\n" + str + NOR;
        }
        write(str);
}

// ���ص�ǰʱ�����ܼ������ַ������أ���һ���ǡ�1��
public string get_week_num(int dtime)
{
        int strweek, strtemp;
        sscanf(ctime(dtime), "%s %s", strweek, strtemp);
        return week_time[strweek];
}


void create()
{
        seteuid(getuid());
        restore();
        set_heart_beat(10); // 20������һ��

        set("channel_id", HIY "�ʹ��" NOR);
}

void remove(){save();}

// ����ȫ��ͨ��
public void do_channel(string ch, string msg)
{
        CHANNEL_D->do_channel(this_object(), ch, msg);
}

public void mud_shutdown(){save();}

/* ÿ1���Ӵε����� ���ڼ������
   ͨ��dbase��¼ÿ����ϴξٰ��ʱ�䣬������Ϊ������������ظ����л�δ����
   sday �����ܼ� ����һ��sday = "1"
   query("huodong_info/sday, ([
        "���1"  : ����ʱ��,
        "���2"  : ����ʱ��,
   ]))
*/
void heart_beat()
{
        string wk, strtime, str_hour, str_min, today;
        string *keys_strtime;
        int nhour, nmin, ntime;
        
        ntime = time(); 
        wk = get_week_num(ntime);
        strtime = MEMBER_D->bjtime(ntime, 0);
        keys_strtime = explode(strtime, ":");
        str_hour = keys_strtime[3];
        str_min = keys_strtime[4];
        sscanf(str_hour, "%d", nhour);
        sscanf(str_min, "%d", nmin);

        today = sprintf("%d", ntime / 86400);
        
        switch(wk) // ���ڼ�
        {
        case "1": // ��̨��� 19:30-23:30
                if (! query("huodong_info/" + today + "/��̨���")) // ��δ����
                {
                        if (nhour == 19)
                        {
                                // ��ʼ�
                                do_channel("chat", HIG "������ս��Ѿ���������ӭ��̨һչ���֣�" +
                                                       "����� help biwu ������\n" NOR);
                                // ��¼��ʼʱ��
                                set("huodong_info/" + today + "/��̨���", ntime);
                        }
                }
        break;
        
        case "2": // "����ս��", "19:00-22:00"
                if (! query("huodong_info/" + today + "/����ս��")) // ��δ����
                {
                        if (nhour == 19)
                        {
                                // ��ʼ�
                                do_channel("chat", HIG "����ս����Ѿ�������Ϊ��������ս�ɡ�" +
                                                       "����� help war_free ������\n" NOR);
                                // ��ʼ��
                                WAR_D->init_all_war();
                                // ��¼��ʼʱ��
                                set("huodong_info/" + today + "/����ս��", ntime);
                        }
                }
        break;
        
        case "3": // "����", "����Զ��",20:00-21:30"
                if (! query("huodong_info/" + today + "/����Զ��")) // ��δ����
                {
                        if (nhour == 20)
                        {
                                // ��ʼ�
                                if (! LEAGUE_D->is_in_leaguewar())
                                        LEAGUE_D->start_leaguewar();
                                // ��¼��ʼʱ��
                                set("huodong_info/" + today + "/����Զ��", ntime);
                        }
                }
        break;

        case "4": // "����", "��������ս", "21:30-22:30",
                if (! query("huodong_info/" + today + "/��������ս")) // ��δ����
                {
                        if (nhour == 21 && nmin == 30)
                        {
                                // ��ʼ�
                                if (XYWAR_D->now_status() == 0)
                                        XYWAR_D->start_xywar();
                                // ��¼��ʼʱ��
                                set("huodong_info/" + today + "/��������ս", ntime);
                        }
                }
        break;
        
        case "5": //"����", "�ͷ���ĩ�", "20:00-23:59"
                  //        "���ɴ���ս", "20:00-22:00"
                if (! query("huodong_info/" + today + "/���ɴ���ս")) // ��δ����
                {
                        if (nhour == 20)
                        {
                                // ��ʼ�
                                LEAGUEFIGHT_D->start_leaguefitht();
                                // ��¼��ʼʱ��
                                set("huodong_info/" + today + "/���ɴ���ս", ntime);
                        }
                }               
        break;
        
        case "6": // ����
                  //        "����", "�ͷ���ĩ�", "00:00-23:59"
                  //        "����ս��", "13:00-20:00"
                  //        "����Զ��", "20:00-21:30"
                if (! query("huodong_info/" + today + "/����ս��")) // ��δ����
                {
                        if (nhour == 13)
                        {
                                // ��ʼ�
                                do_channel("chat", HIG "����ս����Ѿ�������Ϊ��������ս�ɡ�" +
                                                       "����� help war_free ������\n" NOR);
                                // ��ʼ��
                                WAR_D->init_all_war();                      
                                // ��¼��ʼʱ��
                                set("huodong_info/" + today + "/����ս��", ntime);
                        }
                }
                if (! query("huodong_info/" + today + "/����Զ��")) // ��δ����
                {
                        if (nhour == 20)
                        {
                                // ��ʼ�
                                if (! LEAGUE_D->is_in_leaguewar())
                                        LEAGUE_D->start_leaguewar();
                                // ��¼��ʼʱ��
                                set("huodong_info/" + today + "/����Զ��", ntime);
                        }
                }
        break;

        case "7":  // ����
                  //        "����", "�ͷ���ĩ�", "00:00-23:59"
                  //        "��������ս", "21:30-22:30"
                  //        "���ɴ���ս", "20:00-22:30"
                if (! query("huodong_info/" + today + "/��������ս")) // ��δ����
                {
                        if (nhour == 21 && nmin == 30)
                        {
                                // ��ʼ�
                                if (XYWAR_D->now_status() == 0)
                                        XYWAR_D->start_xywar();
                                // ��¼��ʼʱ��
                                set("huodong_info/" + today + "/��������ս", ntime);
                        }
                }
                if (! query("huodong_info/" + today + "/���ɴ���ս")) // ��δ����
                {
                        if (nhour == 20)
                        {
                                // ��ʼ�
                                LEAGUEFIGHT_D->start_leaguefitht();
                                // ��¼��ʼʱ��
                                set("huodong_info/" + today + "/���ɴ���ս", ntime);
                        }
                }
        break;  

        default:
        return;
        }

        return;
}

// ����city biwu_dating ,yinghao_dating, xinrui_datin����
// �Ƿ���Կ�ʼ����
public int can_start_huodong(string huodong)
{
        string wk, strtime, str_hour, str_min, today;
        string *keys_strtime;
        int nhour, nmin, ntime;
        
        ntime = time();
        wk = get_week_num(ntime);
        strtime = MEMBER_D->bjtime(ntime, 0);
        keys_strtime = explode(strtime, ":");
        str_hour = keys_strtime[3];
        str_min = keys_strtime[4];
        sscanf(str_hour, "%d", nhour);
        sscanf(str_min, "%d", nmin);
        str_min = keys_strtime[4];
        today = sprintf("%d", ntime / 86400);
        
        switch(huodong)
        {
        case "biwu": // ������ 19:00 - 23:00
                if (wk == "1" && 
                   nhour >= 19 && nhour < 23)return 1;
                else
                {
                        return 0;
                }
        break;
        case "league.war":
        break;
        case "league.fight":
        break;  
        case "war_free": // "�ܶ�", "����ս��", "19:00-22:00" ���� "����ս��", "13:00-20:00"
                if (wk == "2" &&
                   nhour >= 19&& 
                   nhour < 22)return 1;
                else if (wk == "6" &&
                        (nhour >= 13 && nhour < 20)
                        )return 1;
                else
                        return 0;
        break;
        case "xywar":
        break;
        
        default:
        return 0;
        }

        return 0;
}
