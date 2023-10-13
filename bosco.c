ROM_START( bosco )
    ROM_REGION( 0x10000, REGION_CPU1, 0 )   /* 64k for code for the first CPU  */
    ROM_LOAD( "bos3_1.bin",   0x0000, 0x1000, CRC(96021267) SHA1(bd49b0caabcccf9df45a272d767456a4fc8a7c07) )
    ROM_LOAD( "bos1_2.bin",   0x1000, 0x1000, CRC(2d8f3ebe) SHA1(75de1cba7531ae4bf7fbbef7b8e37b9fec4ed0d0) )
    ROM_LOAD( "bos1_3.bin",   0x2000, 0x1000, CRC(c80ccfa5) SHA1(f2bbec2ea9846d4601f06c0b4242744447a88fda) )
    ROM_LOAD( "bos1_4b.bin",  0x3000, 0x1000, CRC(a3f7f4ab) SHA1(eb26184311bae0767c7a5593926e6eadcbcb680e) )

    ROM_REGION( 0x10000, REGION_CPU2, 0 )   /* 64k for the second CPU */
    ROM_LOAD( "bos1_5c.bin",  0x0000, 0x1000, CRC(a7c8e432) SHA1(3607be75daa10f1f98dbfd9e600c5ba513130d44) )
    ROM_LOAD( "bos3_6.bin",   0x1000, 0x1000, CRC(4543cf82) SHA1(50ad7d1ab6694eb8fab88d0fa79ee04f6984f3ca) )

    ROM_REGION( 0x10000, REGION_CPU3, 0 )   /* 64k for the third CPU  */
    ROM_LOAD( "2900.3e",      0x0000, 0x1000, CRC(d45a4911) SHA1(547236adca9174f5cc0ec05b9649618bb92ba630) )

    ROM_REGION( 0x1000, REGION_GFX1, ROMREGION_DISPOSE )
    ROM_LOAD( "5300.5d",      0x0000, 0x1000, CRC(a956d3c5) SHA1(c5a9d7b1f9b4acda8fb9762414e085cb5fb80c9e) )

    ROM_REGION( 0x1000, REGION_GFX2, ROMREGION_DISPOSE )
    ROM_LOAD( "5200.5e",      0x0000, 0x1000, CRC(e869219c) SHA1(425614cd0642743a82ef9c1aada29774a92203ea) )

    ROM_REGION( 0x0100, REGION_GFX3, ROMREGION_DISPOSE )
    ROM_LOAD( "prom.2d",      0x0000, 0x0100, CRC(9b69b543) SHA1(47af3f67e50794e839b74fe61197af2228084efd) )    /* dots */

    ROM_REGION( 0x0260, REGION_PROMS, 0 )
    ROM_LOAD( "bosco.6b",     0x0000, 0x0020, CRC(d2b96fb0) SHA1(54c100ec9d173d7dd48a453ebed5f625053cb6e0) )    /* palette */
    ROM_LOAD( "bosco.4m",     0x0020, 0x0100, CRC(4e15d59c) SHA1(3542ead6421d169c3569e121ec2be304e108787c) )    /* lookup table */
    ROM_LOAD( "prom.1d",      0x0120, 0x0100, CRC(de2316c6) SHA1(0e55c56046331888d1d3f0d9823d2ceb203e7d3f) )    /* ?? */
    ROM_LOAD( "prom.2r",      0x0220, 0x0020, CRC(b88d5ba9) SHA1(7b97a38a540b7ca4b7d9ae338ec38b9b1a337846) )    /* ?? */
    ROM_LOAD( "prom.7h",      0x0240, 0x0020, CRC(87d61353) SHA1(c7493e52662c921625676a4a4e8cf4371bd938b7) )    /* ?? */

    ROM_REGION( 0x0200, REGION_SOUND1, 0 )  /* sound prom */
    ROM_LOAD( "bosco.spr",    0x0000, 0x0100, CRC(ee8ca3a8) SHA1(48d5d9e8c9ca966edad0d5198bb445f6ecceb037) )
    ROM_LOAD( "prom.5c",      0x0100, 0x0100, CRC(77245b66) SHA1(0c4d0bee858b97632411c440bea6948a74759746) )    /* timing - not used */

    ROM_REGION( 0x3000, REGION_SOUND2, 0 )  /* ROMs for digitised speech */
    ROM_LOAD( "4900.5n",      0x0000, 0x1000, CRC(09acc978) SHA1(2b264aaeb6eba70ad91593413dca733990e5467b) )
    ROM_LOAD( "5000.5m",      0x1000, 0x1000, CRC(e571e959) SHA1(9c81d7bec73bc605f7dd9a089171b0f34c4bb09a) )
    ROM_LOAD( "5100.5l",      0x2000, 0x1000, CRC(17ac9511) SHA1(266f3fae90d2fe38d109096d352863a52b379899) )
    