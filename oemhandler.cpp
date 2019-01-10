#include <host-ipmid/ipmid-api.h>

#include <iostream>

ipmi_ret_t ipmi_inspur_oem_hello(ipmi_netfn_t netfn, ipmi_cmd_t cmd,
                                 ipmi_request_t request,
                                 ipmi_response_t response,
                                 ipmi_data_len_t data_len,
                                 ipmi_context_t context)
{
    ipmi_ret_t rc = IPMI_CC_OK;
    *data_len = 1;
    uint8_t record = 0x3c;
    memcpy(response, &record, 1);
    std::cout << "hello world 1" << std::endl;

    return rc;
}

void register_netfn_ibm_oem_commands() __attribute__((constructor));
void register_netfn_ibm_oem_commands()
{
    std::cout << "Register inspur oem command" << std::endl;

    ipmi_register_callback(0x3c, 0x3c, NULL, ipmi_inspur_oem_hello,
                           SYSTEM_INTERFACE);
}

