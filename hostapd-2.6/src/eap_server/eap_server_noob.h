#ifndef EAPOOB_H
#define EAPOOB_H


/* Configuration file */
#define CONF_FILE               "eapoob.conf"

/**
 * All the pre-processors of EAP-NOOB
 **/

#if 0
/*  Unused macros */
#define NUM_OF_VERSIONS         1
#define PEER_ID_DEFAULT_REALM   "noob@eap-noob.net"
#define PEER_ID_DEFAULT         "noob"
#define SERVER_INFO             "Believe_me_i_am_an_authenticated_server"
#define PUBLIC_KEY              "A Very secret public key"
#define FIXED_LENGTH            6
#endif

#define RESERVED_DOMAIN         "eap-noob.net"
#define VERSION_ONE             1
#define SUITE_ONE               1
#define EAP_NOOB_NOOB_LEN       16
#define EAP_NOOB_NONCE_LEN      32
#define EAP_SHARED_SECRET_LEN   32
#define ALGORITHM_ID            "EAP-NOOB"
#define ALGORITHM_ID_LEN        8

/* MAX values for fields */
#define MAX_SUP_VER             3
#define MAX_SUP_CSUITES         10
#define MAX_CONF_LEN            500
#define MAX_INFO_LEN            500
#define MAX_PEERID_LEN          22
#define MAX_LINE_SIZE           1000

#define KDF_LEN                 288
#define MSK_LEN                 64
#define EMSK_LEN                64
#define AMSK_LEN                64
#define KZ_LEN                  32
#define KMS_LEN                 32
#define KMP_LEN                 32
#define MAC_LEN                 16
#define MAX_X25519_LEN          48
#define HASH_LEN                16

/* Valid or Invalid states */
#define INVALID                 0
#define VALID                   1
#define NUM_OF_STATES           5
#define MAX_MSG_TYPES           8

/* OOB DIRECTIONS */
#define PEER_TO_SERVER          1
#define SERVER_TO_PEER          2
#define BOTH_DIRECTIONS         3

#define SUCCESS                 1
#define FAILURE                 0

#define DONE                    1
#define NOT_DONE                0

/* Maximum allowed waiting exchages */
#define MAX_WAIT_EXCHNG_TRIES   5

/* keywords for json encoding and decoding */
#define TYPE                    "Type"
#define ERRORINFO               "ErrorInfo"
#define ERRORCODE               "ErrorCode"
#define VERS                    "Vers"
#define CRYPTOSUITES            "Cryptosuites"
#define DIRS                    "Dirs"
#define NS                      "Ns"
#define SLEEPTIME               "SleepTime"
#define PEERID                  "PeerId"
#define PKS                     "PKs"
#define SERVERINFO              "ServerInfo"
#define MACS                    "MACs"
#define PEERINFO_SERIAL         "Serial"
//#define PEERINFO_TYPE           "Type"
//#define PEERINFO_MAKE           "Make"
#define VERP                    "Verp"
#define CRYPTOSUITEP            "Cryptosuitep"
#define DIRP                    "Dirp"
#define NP                      "Np"
#define PKP                     "PKp"
#define PEERINFO                "PeerInfo"
#define PEERSTATE               "state"
#define NOOBID                  "NoobId"
#define MACP                    "MACp"
#define X_COORDINATE            "x"
#define Y_COORDINATE            "y"
#define KEY_TYPE                "kty"
#define CURVE                   "crv"
#define REALM                   "Realm"
#define SERVERINFO_NAME         "Name"
#define SERVERINFO_URL          "Url"

#define ECDH_KDF_MAX            (1 << 30)

#define PEERID_RCVD             0x0001
#define DIRP_RCVD               0x0002
#define CRYPTOSUITEP_RCVD       0x0004
#define VERSION_RCVD            0x0008
#define NONCE_RCVD              0x0010
#define MAC_RCVD                0x0020
#define PKEY_RCVD               0x0040
#define INFO_RCVD               0x0080
#define STATE_RCVD              0x0100
#define MINSLP_RCVD             0x0200
#define SERV_NAME_RCVD          0x0400
#define SERV_URL_RCVD           0x0800
#define HINT_RCVD               0x1000
#define WE_COUNT_RCVD           0x2000
#define REALM_RCVD              0x4000
#define ENCODE_RCVD             0x8000

#define TYPE_ONE_PARAMS         (PEERID_RCVD|VERSION_RCVD|CRYPTOSUITEP_RCVD|DIRP_RCVD|INFO_RCVD)
#define TYPE_TWO_PARAMS         (PEERID_RCVD|NONCE_RCVD|PKEY_RCVD)
#define TYPE_THREE_PARAMS       (PEERID_RCVD)
#define TYPE_FOUR_PARAMS        (PEERID_RCVD|MAC_RCVD)
#define TYPE_FIVE_PARAMS        (PEERID_RCVD|CRYPTOSUITEP_RCVD|INFO_RCVD)
#define TYPE_SIX_PARAMS         (PEERID_RCVD|NONCE_RCVD)
#define TYPE_SEVEN_PARAMS       (PEERID_RCVD|MAC_RCVD)
#define TYPE_HINT_PARAMS        (PEERID_RCVD|HINT_RCVD)

#define CONF_PARAMS             (DIRP_RCVD|CRYPTOSUITEP_RCVD|VERSION_RCVD|SERV_NAME_RCVD|SERV_URL_RCVD|WE_COUNT_RCVD|REALM_RCVD|ENCODE_RCVD)
#define DB_NAME                 "peer_connection_db"
#define DEVICE_TABLE            "devices"
#define PEER_TABLE              "peers_connected"

/*SQL query to create peer connection database*/
#define CREATE_CONNECTION_TABLE                     \
    "CREATE TABLE IF NOT EXISTS peers_connected(    \
    PeerId TEXT PRIMARY KEY,                        \
    Vers INTEGER,                                   \
    Verp INTEGER,                                   \
    Cryptosuites INTEGER,                           \
    Cryptosuitep INTEGER,                           \
    Dirs INTEGER,                                   \
    Dirp INTEGER,                                   \
    Ns TEXT,                                        \
    Np TEXT,                                        \
    PKs TEXT,                                       \
    PKp TEXT,                                       \
    ServerInfo TEXT,                                \
    PeerInfo TEXT,                                  \
    NoobId TEXT,                                    \
    Noob TEXT,                                      \
    Hoob TEXT,                                      \
    ErrorCode INTEGER,                              \
    Z TEXT,                                         \
    Kz TEXT,                                        \
    Kms TEXT,                                       \
    Kmp TEXT,                                       \
    server_state INTEGER,                           \
    oob_received_flag INTEGER,                      \
    last_time UNSIGNED BIG INT,                     \
    sleep_count INTEGER,                            \
    Mac1Input TEXT,                                 \
    Mac2Input TEXT)                                 \
    "

/*
      last_time UNSIGNED BIG INT,                   \ stored but never read!
      peer_state INTEGER,                           \
      OobRetries INTEGER DEFAULT 0,                 \
*/

#define CREATE_RADIUS_TABLE                         \
    "CREATE TABLE IF NOT EXISTS radius(             \
    called_st_id TEXT,                              \
    calling_st_id  TEXT,                            \
    NAS_id TEXT,                                    \
    user_name TEXT PRIMARY KEY)"

#define EAP_NOOB_FREE(_D)                           \
    if (_D) {                                       \
        os_free(_D);                                \
        (_D) = NULL;                                \
    }                                               

/* TA: canot do this for the reference count */
/*
#define EAP_NOOB_JSON_FREE(_J)                      \
    if (_J) {                                       \
        json_decref(_J);                   \
        _J = NULL;                                  \
    }
*/

#define EAP_NOOB_FREE_MALLOC(_D,_l)                 \
    EAP_NOOB_FREE(_D)                               \
    (_D)=os_malloc(_l)


#define EAP_NOOB_CB_GET_B64(_D64,_D,_l)             \
    EAP_NOOB_FREE(_D64)                             \
    EAP_NOOB_FREE(_D)                               \
    _D64 = os_strdup(fieldValue[i]);                \
    _l = eap_noob_Base64Decode(_D64,&_D)


#define EAP_NOOB_SET_DONE(_data,_v)                 \
    (_data)->peer_attr->is_done = (_v)


#define EAP_NOOB_SET_SUCCESS(_data,_v)              \
    (_data)->peer_attr->is_success = (_v)


#define EAP_NOOB_SET_ERROR(_pdata,_v)               \
    if (_pdata) {                                   \
        (_pdata)->next_req = NONE;                  \
        (_pdata)->err_code = _v;                    \
    }

#define EAP_NOOB_CHANGE_STATE(_data,_s)             \
    if ((_data) && ((_data)->peer_attr)) {          \
        (_data)->peer_attr->server_state = (_s);      \
    }


 /* Flag used during KDF and MAC generation */
enum {COMPLETION_EXCHANGE, RECONNECT_EXCHANGE, RECONNECT_EXCHANGE_NEW};

enum {UNREGISTERED_STATE, WAITING_FOR_OOB_STATE, OOB_RECEIVED_STATE, 
    RECONNECTING_STATE, REGISTERED_STATE};

enum {NONE, EAP_NOOB_TYPE_1, EAP_NOOB_TYPE_2, EAP_NOOB_TYPE_3,
      EAP_NOOB_TYPE_4, EAP_NOOB_TYPE_5, EAP_NOOB_TYPE_6,
      EAP_NOOB_TYPE_7, EAP_NOOB_TYPE_8};

enum {UPDATE_ALL, UPDATE_STATE, UPDATE_STATE_MINSLP,
      UPDATE_PERSISTENT_KEYS_SECRET, UPDATE_STATE_ERROR,
      UPDATE_OOB};

enum eap_noob_err_code{NO_ERROR, E1001, E1002, E1003, E1004, E1005,
     E1006, E1007, E2001, E2002, E3001, E3002, E3003, E4001};

enum {HOOB_TYPE, MACS_TYPE, MACP_TYPE};

struct eap_noob_global_conf {
    int read_conf;
    int max_we_count;
    char * realm;
    int len_realm;
    int oob_encode;
};

struct eap_noob_ecdh_kdf_out {

    u8 * msk;
    char * msk_b64;
    u8 * emsk;
    char * emsk_b64;
    u8 * amsk;
    char * amsk_b64;
    u8 * Kms;
    char * kms_b64;
    u8 * Kmp;
    char * kmp_b64;
    u8 * Kz;
    char * kz_b64;
};

struct eap_noob_ecdh_kdf_nonce {
    u8 * Ns;
    char * nonce_server_b64;
    u8 * Np;
    char * nonce_peer_b64;
};

struct eap_noob_oob_data {

    char * noob_b64;
    size_t noob_len;
    u8 * noob;

    char * hoob_b64;
    size_t hoob_len;
    u8 * hoob;

    char * hint_b64;
    size_t hint_len;
    u8 * hint;
};

struct eap_noob_ecdh_key_exchange {
    EVP_PKEY * dh_key;

    char * x_peer_b64;
    char * y_peer_b64;

    char * x_b64;
    size_t x_len;
    char * y_b64;
    size_t y_len;

    json_t * jwk_serv;
    json_t * jwk_peer;

    u8 * shared_key;
    char * shared_key_b64;
    size_t shared_key_b64_len;
};

struct eap_noob_peer_data {

    u32 version;
    u32 cryptosuite;
    u32 dir;
    u32 sleeptime;
    u32 recv_msg;
    u32 rcvd_params;
    u32 sleep_count;
    int oob_recv;

    u8 peer_state;
    u8 server_state;
    u8 next_req;
    u8 is_done;
    u8 is_success;

    char * peerID_rcvd;
    char * PeerId;
    char * peerinfo;
    char * peer_snum;  /* Only set, not used */
    char * mac;
    Boolean record_present;
    Boolean hint_required;

    enum eap_noob_err_code err_code;

    struct timespec last_time;

    struct eap_noob_ecdh_key_exchange * ecdh_exchange_data;
    struct eap_noob_oob_data * oob_data;
    struct eap_noob_ecdh_kdf_nonce * kdf_nonce_data;
    struct eap_noob_ecdh_kdf_out * kdf_out;
    json_t * Mac1Input;
    json_t * Mac2Input;
    char * Mac1InputStr;
    char * Mac2InputStr;
};

struct eap_noob_server_config_params {
    char * Serv_name;
    char * Serv_URL;
};

struct eap_noob_server_data {
    u32 version[MAX_SUP_VER];
    u32 cryptosuite[MAX_SUP_CSUITES];
    u32 dir;
    char * serverinfo;
    u32 config_params;
    struct eap_noob_server_config_params * server_config_params;
};

struct eap_noob_server_context {
    struct eap_noob_peer_data * peer_attr;
    struct eap_noob_server_data * server_attr;
    char * db_name;
    char * db_table_name;
    sqlite3 * servDB;
};


const int error_code[] = {0, 1001, 1002, 1003, 1004, 1005, 1006, 1007,
                          2001, 2002, 3001, 3002, 3003, 4001};

const char *error_info[] = {
    "No error",
    "Invalid NAI or peer state",
    "Invalid message structure",
    "Invalid data",
    "Unexpected message type",
    "Unexpected peer identifier",
    "Unrecognized OOB message identifier",
    "Invalid ECDH key",
    "Unwanted peer",
    "State mismatch, user action required",
    "No mutually supported protocol version",
    "No mutually supported cryptosuite",
    "No mutually supported OOB direction",
    "MAC verification failure" };


/* This 2-D arry is used for state validation.
 * Cloumn number represents the state of Peer and the row number
 * represents the server state
 * The states are in squence as: {UNREGISTERED_STATE, WAITING_FOR_OOB_STATE, 
 *  OOB_RECEIVED_STATE, RECONNECTING_STATE, REGISTERED_STATE}
 * for both peer and server */
const int state_machine[][5] = {
    {VALID, INVALID, INVALID, INVALID, INVALID},
    {VALID, VALID,   VALID,   INVALID, INVALID},
    {VALID, VALID,   VALID,   INVALID, INVALID},
    {VALID, INVALID, INVALID, VALID,   VALID},
    {VALID, INVALID, INVALID, VALID,   INVALID}
};

const int next_request_type[] = {
    EAP_NOOB_TYPE_1,   NONE,            NONE,            NONE,            NONE,
    EAP_NOOB_TYPE_1,   EAP_NOOB_TYPE_3, EAP_NOOB_TYPE_4, NONE,            NONE,
    EAP_NOOB_TYPE_1,   EAP_NOOB_TYPE_4, EAP_NOOB_TYPE_4, NONE,            NONE,
    EAP_NOOB_TYPE_1,   NONE,            NONE,            EAP_NOOB_TYPE_5, EAP_NOOB_TYPE_5,
    EAP_NOOB_TYPE_1,   NONE,            NONE,            EAP_NOOB_TYPE_5, NONE
};


/*server state vs message type matrix*/
const int state_message_check[NUM_OF_STATES][MAX_MSG_TYPES] = {
    {VALID, VALID,   VALID,   INVALID,  INVALID,  INVALID,  INVALID,  INVALID}, //UNREGISTERED_STATE
    {VALID, VALID,   VALID,   VALID,    VALID,    INVALID,  INVALID,  INVALID}, //WAITING_FOR_OOB_STATE
    {VALID, VALID,   VALID,   INVALID,  VALID,    INVALID,  INVALID,  INVALID}, //OOB_RECEIVED_STATE
    {VALID, INVALID, INVALID, INVALID,  INVALID,  VALID,    VALID,    VALID},   //RECONNECT
    {VALID, INVALID, INVALID, INVALID,  VALID,    INVALID,  INVALID,  INVALID}, //REGISTERED_STATE
};

#define EAP_NOOB_STATE_VALID                                                              \
    (state_machine[data->peer_attr->server_state][data->peer_attr->peer_state]  == VALID)   \

/*Function prototypes*/
static json_t * eap_noob_prepare_vers_arr(const struct eap_noob_server_context * data);
static json_t * eap_noob_prepare_csuites_arr(const struct eap_noob_server_context * data);
#endif
