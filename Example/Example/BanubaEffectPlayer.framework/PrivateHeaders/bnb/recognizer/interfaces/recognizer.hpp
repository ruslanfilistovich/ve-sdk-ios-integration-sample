/// \file
/// \addtogroup Recognizer
/// @{
///
// AUTOGENERATED FILE - DO NOT MODIFY!
// This file generated by Djinni from recognizer.djinni

#pragma once

#include "bnb/types/interfaces/frame_data.hpp"
#include <bnb/utils/defs.hpp>
#include <cstdint>
#include <memory>
#include <unordered_set>

namespace bnb { namespace interfaces {

class feature;
enum class face_search_mode;
enum class feature_id;

class BNB_EXPORT recognizer {
public:
    virtual ~recognizer() {}

    static std::shared_ptr<recognizer> create();

    static int64_t get_feature_id(feature_id feature);

    virtual std::shared_ptr<feature> get_feature(feature_id feature) = 0;

    virtual void set_features(const std::unordered_set<feature_id> & features) = 0;

    virtual void add_feature(const std::shared_ptr<feature> & feature, const std::unordered_set<feature_id> & dependencies, bool needs_gpu) = 0;

    virtual void remove_feature(const std::shared_ptr<feature> & feature) = 0;

    /** sets maximum allowed face results, if face tracking feature is present */
    virtual void set_max_faces(int32_t num) = 0;

    virtual void set_offline_mode(bool on) = 0;

    /**
     * Set flag which enable NN's features. True by default, if device compatible with NN player
     * When this flag is false, recognizer will skip NN-dependent features during set_features call.
     * In case when device have no NN player support (is_device_nn_compatible return false),
     * setting enable to true have no any effect
     */
    virtual void set_nn_enable(bool enable) = 0;

    virtual bool get_nn_enable() const = 0;

    /** Check if device compatible with NN player. */
    virtual bool is_device_nn_compatible() = 0;

    /** Clear pipeline state and set face search mode */
    virtual void set_face_search_mode(face_search_mode mode) = 0;

    virtual void process(const std::shared_ptr<::bnb::interfaces::frame_data> & frame_data) = 0;
};

} }  // namespace bnb::interfaces
/// @}
