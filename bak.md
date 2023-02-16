\#define READ_EVTCNT_CMD "cat /proc/interrupts | grep lombo-pmc | busybox awk -F \" \" '{ print $2 }'"



  FILE* pfile = popen(READ_EVTCNT_CMD, "r");

  if(pfile == NULL)

  {

​    MLOGE("execute cmd failed\n");

​    goto RETURN;

  }



  char buf[10] = {0};

  int rlen = fread(buf, 1, 9, pfile);

  pclose(pfile);

  if(rlen < 1)

  {

​    MLOGE("check pwr evtcnt failed\n");

​    goto RETURN;

  }



  int evtcnt = atoi(buf);

  MLOGI("evtcnt1:%s\n", buf);



  MLOGI("time:%d\n", time);

  //Wait key operation





  for(int i = 0; i < time * 1000; i += 100){

​    pfile = popen(READ_EVTCNT_CMD, "r");

​    if(pfile == NULL)

​    {

​      MLOGE("execute cmd failed2\n");

​      goto RETURN;

​    }



​    memset(buf, 0, 10);

​    rlen = fread(buf, 1, 9, pfile);

​    MLOGI("evtcnt2:%s\n", buf);

​    pclose(pfile);

​    if(rlen < 1)

​    {

​      MLOGE("check pwr evtcnt failed2\n");

​      goto RETURN;

​    }

​    //Judgment command

​    if(evtcnt < atoi(buf)){

​      MLOGI("PWR-KEY effective\n");

​      returnRet[6] = 0x31;

​      result[0] = '1';

​      break;

​    }

​    MLOGI("result is waitting ,time :%d ms\n", i);

​    //Timeout judgment

​    if(i == time * 1000 - 100){

​      MLOGE("PWR-KEY ineffective\n");

​      goto RETURN;

​    }

​    usleep(1000 * 100);

  }

\#undef READ_EVTCNT_CMD