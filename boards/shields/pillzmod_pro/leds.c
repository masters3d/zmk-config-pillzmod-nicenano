#include <zephyr/device.h>
#include <zephyr/devicetree.h>
#include <zephyr/drivers/led.h>
#include <zephyr/kernel.h>
#include <zephyr/init.h>
#include <zmk/hid_indicators.h>
#include <zmk/events/hid_indicators_changed.h>

#define LED_GPIO_NODE_ID DT_COMPAT_GET_ANY_STATUS_OKAY(gpio_leds)

// GPIO-based LED device
static const struct device *led_dev = DEVICE_DT_GET(LED_GPIO_NODE_ID);

static int led_keylock_listener_cb(const zmk_event_t *eh) {
    zmk_hid_indicators_t flags = zmk_hid_indicators_get_current_profile();
    unsigned int capsBit = 1 << (HID_USAGE_LED_CAPS_LOCK - 1);
    unsigned int numBit = 1 << (HID_USAGE_LED_NUM_LOCK - 1);
    unsigned int scrollBit = 1 << (HID_USAGE_LED_SCROLL_LOCK - 1);

    if (flags & capsBit) {
        led_on(led_dev, DT_NODE_CHILD_IDX(DT_ALIAS(led_caps)));
    } else {
        led_off(led_dev, DT_NODE_CHILD_IDX(DT_ALIAS(led_caps)));
    }

    if (flags & numBit) {
        led_on(led_dev, DT_NODE_CHILD_IDX(DT_ALIAS(led_num)));
    } else {
        led_off(led_dev, DT_NODE_CHILD_IDX(DT_ALIAS(led_num)));
    }

    if (flags & scrollBit) {
        led_on(led_dev, DT_NODE_CHILD_IDX(DT_ALIAS(led_scroll)));
    } else {
        led_off(led_dev, DT_NODE_CHILD_IDX(DT_ALIAS(led_scroll)));
    }

    return 0;
}

ZMK_LISTENER(led_indicators_listener, led_keylock_listener_cb);
ZMK_SUBSCRIPTION(led_indicators_listener, zmk_hid_indicators_changed);

static int leds_init(const struct device *device) {
    if (!device_is_ready(led_dev)) {
        return -ENODEV;
    }

    return 0;
}

// run leds_init on boot
SYS_INIT(leds_init, APPLICATION, CONFIG_APPLICATION_INIT_PRIORITY);