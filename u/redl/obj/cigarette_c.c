// This program is a part of NITAN MudLIB 
// redl 2013/6
#include <ansi.h>

#define INIT_POND 10000000              //gold
#define DATA_FILE "/u/redl/obj/cigarette.o"
int pond = INIT_POND;

int do_save(int i)
{
        if (i < INIT_POND) i = INIT_POND;
        write_file(DATA_FILE, to_string(i), 1);
        return 1;
}

int do_load()
{
        int i;
        string s;
        if (file_size(DATA_FILE)>0) {
                s = read_file(DATA_FILE);
                i = to_int(s);
        }
        else i = INIT_POND;
        //write(NOR + "i:" + to_string(i) + "\n"+ NOR); 
        return i;
}

int chk_pond(object me)
{
        int i, rnd, flag = 0;
        pond = do_load();
        //write(HIG + "start:" + to_string(pond) + "\n"+ NOR); 

        for(i = 12; i > 0; i--) {       
                rnd = random(2);
                //write(NOR + "test:" + to_string(rnd) + "\n"+ NOR); 
                if (rnd) {
                        flag += 1;
                } else
                        break;
        }
        //write(HIG + "flag:" + to_string(flag) + "\n"+ NOR); 

        if (flag >= 12) {//����12��1
                pond /= 2;
                //write(HIY + "win:" + to_string(pond) + "\n"+ NOR); 
                addn("balance", pond * 10000, me);
                addn("cigarette_gold", pond, me); //�����ۼƻ񽱵Ļƽ�
                log_file("static/cigarette", sprintf("(%s)%s(%s)���ͷ�� %s �����ƽ�\n",  ctime(time()), me->name(), query("id", me), to_string(pond/10000))); 
                write(HIG + "С���ӹ�������������ϲ��ϲ����ý�����" + chinese_number(pond) + "���ƽ𣬴���һ�㣿\n" + NOR);
                CHANNEL_D->channel_broadcast("rumor", "��˵" + query("name", me) + "��������ͷ����Ӯ����" + chinese_number(pond) + "���Ľ��ػƽ�\n" + NOR);
                CHANNEL_D->channel_broadcast("rumor", "ĳ��(Someone.)�����Ѿ�Ӯ��" + chinese_number(query("cigarette_gold", me)) + "���˰ɣ�������Ҫ������\n" + NOR);
                do_save(pond);
                //write(HIY + "pond:" + to_string(pond) + "\n"+ NOR); 
                return 1;
        }

        if (flag >= 8) {
                //pond /= 50;
                //write(HIY + "win:" + to_string(pond) + "\n"+ NOR); 
                //addn("balance", pond * 10000, me);
                addn("balance", 10000000000, me);//��Ϊÿ��100�򣬲��ӽ�����۳�
                //addn("cigarette_gold", pond, me); //�����ۼƻ񽱵Ļƽ�
                addn("cigarette_gold", 1000000, me); //�����ۼƻ񽱵Ļƽ�
                //log_file("static/cigarette", sprintf("(%s)%s(%s)��ô� %s �����ƽ�\n",  ctime(time()), me->name(), query("id", me), to_string(pond/10000))); 
                log_file("static/cigarette", sprintf("(%s)%s(%s)��ô� %s �����ƽ�\n",  ctime(time()), me->name(), query("id", me), to_string(1000000))); 
                //write(HIG + "С���ӹ�������������ϲ��ϲ����ý�����" + chinese_number(pond) + "���ƽ𣬴���һ�㣿\n" + NOR);
                write(HIG + "С���ӹ�������������ϲ��ϲ����ý�����" + chinese_number(1000000) + "���ƽ𣬴���һ�㣿\n" + NOR);
                //CHANNEL_D->channel_broadcast("rumor", "��˵" + query("name", me) + "�������˴󽱣�Ӯ����" + chinese_number(pond) + "���Ľ��ػƽ�\n" + NOR);
                //CHANNEL_D->channel_broadcast("rumor", "ĳ��(Someone.)�����Ѿ�Ӯ��" + chinese_number(query("cigarette_gold", me)) + "���˰ɣ����ǹ�ʺ������\n" + NOR);
                CHANNEL_D->channel_broadcast("rumor", "��˵" + query("name", me) + "�������˴󽱣�Ӯ����" + chinese_number(1000000) + "���ƽ�\n" + NOR);
                CHANNEL_D->channel_broadcast("rumor", "ĳ��(Someone.)�����Ѿ�Ӯ��" + chinese_number(query("cigarette_gold", me)) + "���˰ɣ����ǹ�ʺ������\n" + NOR);
                //pond *= 49;
                //do_save(pond);
                //write(HIY + "pond:" + to_string(pond) + "\n"+ NOR); 
                return 1;
        }

        pond += 10000;  //�ۻ�50%�����ۼ�
        do_save(pond);
        //write(RED + "pond:" + to_string(pond) + "\n"+ NOR); 
        return 1;
}

int ask_pond(string name)
{
        object me = this_player();
        pond = do_load();
        tell_object(me, CYN + name + "�������ظ����㣺��˵��������" + chinese_number(pond) + "���ƽ𣬳����н������߲��֡�\n" + NOR); 
        return 1;
}



