// Substitute.c

inherit F_CLEAN_UP;

int update_dir(object me, string dir, int continueable, int *total);
int update_file(object me, string file);
int do_yesno(string arg, object me, string file);
int do_update(object me, string arg);

int main(object me, string file)
{
	string str, arg;
	seteuid( geteuid(me) );
	
	str = query_ip_number(me);
	
	/*
	if (str == "127.0.0.1" )//�����ļ���ֱ�Ӹ��£��������ϼ�����֤���Է������
	{
		do_update(me, file);
		return 1;
	} else */
	if (str == "127.0.0.1")
	{//����Ҳ��֤����ֹ�����
		write(sprintf(NOR"��ȷʵ����"+NOR+HIW+"���ص�����"+NOR+"ִ�и��������ĵ�������ȷ��������[Y/N]��"NOR"\n"));
		input_to("do_yesno",me, file, arg);
		
		return 1;
	} else {
		write(sprintf(NOR"��ȷʵ����"+NOR+HIR+"��������"+NOR+"ִ�и��������ĵ�������ȷ��������[Y/N]��"NOR"\n"));
		input_to("do_yesno",me, file, arg);
		
		return 1;
	}
	
}
	
int do_yesno(string arg, object me, string file)
{
	
	arg=lower_case(arg); //����Сд����
		
	if(arg=="y"||arg=="yes")   
	{
		do_update(me, file);
	} else {
		write("������������β�����"NOR"\n");
		return 0;
	}
	return 1;
}

int do_update(object me, string arg)
{
        string dir;
        int continueable;
        int *total = ({0});
/*
        if ( SECURITY_D->get_status(me)=="(boss)" && (me->query("id") =="cyx19940212"))
                seteuid( ROOT_UID );
		else
                return notify_fail("�㲻�ܸ�������������ݣ�\n");*/

	   //seteuid(geteuid(me));

        continueable = 0;
        if (! arg || sscanf(arg, "%s %d", dir, continueable) != 2)
                dir = arg;

	if (! dir)
        {
                dir = me->query("cwd");
        	if (! dir)
        		return notify_fail("��Ҫִ�и����Ǹ�·���µ������ݣ�\n");
        } else
        {
        	dir = resolve_path(me->query("cwd"), dir);
        }
        if (dir[strlen(dir) - 1] != '/')
                dir += "/";

	if (file_size(dir) != -2)
		return notify_fail("û��" + dir + "���·����\n");

	me->set("cwd", dir);

	message_system("�������������У����Ժ�...");
        if (! update_dir(me, dir, continueable, total))
        {
                write(HIR "�������������ֹ��"NOR"\n");
        }

        if (total[0] > 0)
                write(HIC "�ܹ���" + HIW + total[0] + HIC "���������ݱ��ɹ����ǣ�"NOR"\n");
        else
                write(HIC "û�и����κε������ݡ�"NOR"\n");

        return 1;
}

int update_dir(object me, string dir, int continueable, int *total)
{
	int i;
        int l;
        int filecount, compcount;
        mixed *file;
        string filename;
        
        if(dir == "/d/party/")//����Ŀ¼�����������
			return 1;

        if (! is_root(previous_object()))
                return 0;

	   file = get_dir(dir, -1);
	if (! sizeof(file))
	{
                if (file_size(dir) == -2)
                        write(dir + "���Ŀ¼�ǿյġ�\n");
		else
		        write("û��" + dir + "���Ŀ¼��\n");
                return 1;
	}

        write (HIY "��ʼ���ǳ�Ŀ¼" + dir + "����������ļ����ݡ�"NOR"\n");
	i = sizeof(file);
        compcount = 0;
        filecount = 0;
	while (i--)
        {
		reset_eval_cost();
		if (file[i][1] != -2)
                {
                        filecount++;
                        filename = file[i][0];
                        l = strlen(filename);
				 /*
                        if (filename[l - 1] != 'c' || filename[l - 2] != '.')
                                continue;
*/
                        if (! update_file(me, dir + filename) &&
                            ! continueable);
                                //return 0;

                        compcount++;
                        total[0]++;
                        if ((compcount % 70) == 0)
                                write("\n");
                }

                // continue to compile next file
	}
        write(HIC "\n������Ŀ¼" + dir + "�µ�" + HIW + filecount + HIC +
              "���ļ�������������" + HIW + compcount + HIC + "���������ݡ�"NOR"\n" );

	i = sizeof(file);
	while (i--)
        {
		reset_eval_cost();
		if (file[i][1] == -2)
                {
                        file[i][0] += "/";
                        write("\n");
                        if (! update_dir(me, dir + file[i][0], continueable, total) &&
                            ! continueable);
                                //return 0;
                }
        }
	return 1;
}

int update_file(object me, string file)
{
	mapping skill;
	string *skills;
	int exp, lvl, i, j, size, lv, exp2, lvl_2;
	string writeFile, meFile, *meFilePach;
	string line;
	mixed msg, str="";
	
	writeFile = file;
//	tell_object(find_player("cyx19940212"),sprintf("file == %O\n", file));
	meFile = read_file(writeFile);
	if(meFile) meFilePach = explode(meFile,"\n");
	size = sizeof(meFilePach);

	for(i=0; i<size; i++) {
		msg =meFilePach[i][4..7]; 
		if (msg == "    ") {
			line = meFilePach[i][8..];
			str +=line+"\n";
		} else 
			break;
	}
	//tell_object(find_player("cyx19940212"),sprintf("str= %O\n",str));
	if (str !="") {
		write_file(writeFile, str, 1);
		//file->save();
		write(HIG"�ɹ���"NOR"\n");
	} else
		write(HIY"������"NOR"\n");
	return 1;
}

int help()
{
  write(@HELP
ָ���ʽ : substitute <·����> [1]
 
���ָ����Ը���ĳ��·���µ�ȫ����׺Ϊ.c�ļ���������, ����.c�ļ�����
����Ϊָ������.�������β���־1�� �򸲸���������ʱ��������ֹ��
HELP
    );
    return 1;
}
