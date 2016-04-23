#include <Face.h>
#include <PhotoDetector.h>

#include <pybind11/pybind11.h>
#include <pybind11/stl.h>

namespace py = pybind11;

PYBIND11_PLUGIN(affdex) {
    py::module m("affdex", "affdex python bindings");

    py::class_<affdex::PhotoDetector>(m, "PhotoDetector")
    .def(py::init<const unsigned int, const affdex::FaceDetectorMode>())
    .def("process", &affdex::PhotoDetector::process);

    py::class_<affdex::Detector>(m, "Detector")
    .def("setDetectAllExpressions", &affdex::Detector::setDetectAllExpressions)
    .def("setDetectAllEmotions", &affdex::Detector::setDetectAllEmotions)
    .def("setDetectAllEmojis", &affdex::Detector::setDetectAllEmojis)
    .def("setDetectGender",  &affdex::Detector::setDetectGender)
    .def("setDetectGlasses",  &affdex::Detector::setDetectGlasses)
    .def("setLicenseString", &affdex::Detector::setLicenseString)
    .def("setImageListener", &affdex::Detector::setImageListener)
    .def("getImageListener", &affdex::Detector::getImageListener)
    .def("start", &affdex::Detector::start)
    .def("stop", &affdex::Detector::stop)
    .def("reset", &affdex::Detector::reset);


    py::class_<affdex::ImageListener>(m, "ImageListener")
    .def("onImageResults", &affdex::ImageListener::onImageResults)
    .def("onImageCapture", &affdex::ImageListener::onImageCapture);

    py::class_<affdex::Face>(m, "Face")
    .def_readwrite("id", &affdex::Face::id)
    .def_readwrite("emotions", &affdex::Face::emotions)
    .def_readwrite("expressions", &affdex::Face::expressions)
    .def_readwrite("measurements", &affdex::Face::measurements)
    .def_readwrite("appearance", &affdex::Face::appearance)
    .def_readwrite("emojis", &affdex::Face::emojis)
    .def_readwrite("featurepoints", &affdex::Face::featurePoints);

    py::enum_<affdex::Gender>(m, "Gender")
    .value("Unknown", affdex::Gender::Unknown)
    .value("Male", affdex::Gender::Male)
    .value("Female", affdex::Gender::Female)
    .export_values();

    py::enum_<affdex::Glasses>(m, "Glasses")
    .value("No", affdex::Glasses::No)
    .value("Yes", affdex::Glasses::Yes)
    .export_values();

    py::enum_<affdex::Emoji>(m, "Emoji")
    .value("Relaxed", affdex::Emoji::Relaxed)
    .value("Smiley", affdex::Emoji::Smiley)
    .value("Laughing", affdex::Emoji::Laughing)
    .value("Kissing", affdex::Emoji::Kissing)
    .value("Disappointed", affdex::Emoji::Disappointed)
    .value("Rage", affdex::Emoji::Rage)
    .value("Smirk", affdex::Emoji::Smirk)
    .value("Wink", affdex::Emoji::Wink)
    .value("StuckOutTongueWinkingEye", affdex::Emoji::StuckOutTongueWinkingEye)
    .value("StuckOutTongue", affdex::Emoji::StuckOutTongue)
    .value("Flushed", affdex::Emoji::Flushed)
    .value("Scream", affdex::Emoji::Scream)
    .value("Unknown", affdex::Emoji::Unknown)
    .export_values();

    py::enum_<affdex::FaceDetectorMode>(m, "FaceDetectorMode")
    .value("LARGE_FACES", affdex::FaceDetectorMode::LARGE_FACES)
    .value("SMALL_FACES", affdex::FaceDetectorMode::SMALL_FACES)
    .export_values();

    py::class_<affdex::FeaturePoint>(m, "FeaturePoint")
    .def(py::init<const int &, const float &, const float &>())
    .def_readwrite("id", &affdex::FeaturePoint::id)
    .def_readwrite("x", &affdex::FeaturePoint::x)
    .def_readwrite("y", &affdex::FeaturePoint::y);

    py::class_<affdex::Appearance>(m, "Appearance")
    .def_readwrite("gender", &affdex::Appearance::gender)
    .def_readwrite("glasses", &affdex::Appearance::glasses);

    py::class_<affdex::Orientation>(m, "Orientation")
    .def(py::init<const float, const float, const float>())
    .def_readwrite("pitch", &affdex::Orientation::pitch)
    .def_readwrite("yaw", &affdex::Orientation::yaw)
    .def_readwrite("roll", &affdex::Orientation::roll);

    py::class_<affdex::Measurements>(m, "Measurements")
    .def_readwrite("orientation", &affdex::Measurements::orientation)
    .def_readwrite("interocularDistance", &affdex::Measurements::interocularDistance);

    py::class_<affdex::Emotions>(m, "Emotions")
    .def_readwrite("joy", &affdex::Emotions::joy)
    .def_readwrite("fear", &affdex::Emotions::fear)
    .def_readwrite("disgust", &affdex::Emotions::disgust)
    .def_readwrite("sadness", &affdex::Emotions::sadness)
    .def_readwrite("anger", &affdex::Emotions::anger)
    .def_readwrite("surprise", &affdex::Emotions::surprise)
    .def_readwrite("contempt", &affdex::Emotions::contempt)
    .def_readwrite("valence", &affdex::Emotions::valence)
    .def_readwrite("engagement", &affdex::Emotions::engagement);

    py::class_<affdex::Emojis>(m, "Emojis")
    .def_readwrite("relaxed", &affdex::Emojis::relaxed)
    .def_readwrite("smiley", &affdex::Emojis::smiley)
    .def_readwrite("laughing", &affdex::Emojis::laughing)
    .def_readwrite("kissing", &affdex::Emojis::kissing)
    .def_readwrite("disappointed", &affdex::Emojis::disappointed)
    .def_readwrite("rage", &affdex::Emojis::rage)
    .def_readwrite("smirk", &affdex::Emojis::smirk)
    .def_readwrite("wink", &affdex::Emojis::wink)
    .def_readwrite("stuckOutTongueWinkingEye",
                   &affdex::Emojis::stuckOutTongueWinkingEye)
    .def_readwrite("stuckOutTongue", &affdex::Emojis::stuckOutTongue)
    .def_readwrite("flushed", &affdex::Emojis::flushed)
    .def_readwrite("scream", &affdex::Emojis::scream)
    .def_readwrite("dominantEmoji", &affdex::Emojis::dominantEmoji);

    py::class_<affdex::Expressions>(m, "Expressions")
    .def_readwrite("smile", &affdex::Expressions::smile)
    .def_readwrite("innerBrowRaise", &affdex::Expressions::innerBrowRaise)
    .def_readwrite("browRaise", &affdex::Expressions::browRaise)
    .def_readwrite("browFurrow", &affdex::Expressions::browFurrow)
    .def_readwrite("noseWrinkle", &affdex::Expressions::noseWrinkle)
    .def_readwrite("upperLipRaise", &affdex::Expressions::upperLipRaise)
    .def_readwrite("lipCornerDepressor", &affdex::Expressions::lipCornerDepressor)
    .def_readwrite("chinRaise", &affdex::Expressions::chinRaise)
    .def_readwrite("lipPucker", &affdex::Expressions::lipPucker)
    .def_readwrite("lipPress", &affdex::Expressions::lipPress)
    .def_readwrite("lipSuck", &affdex::Expressions::lipSuck)
    .def_readwrite("mouthOpen", &affdex::Expressions::mouthOpen)
    .def_readwrite("smirk", &affdex::Expressions::smirk)
    .def_readwrite("eyeClosure", &affdex::Expressions::eyeClosure)
    .def_readwrite("attention", &affdex::Expressions::attention);

    return m.ptr();
}
